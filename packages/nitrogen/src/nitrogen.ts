import { Project } from 'ts-morph'
import { getPlatformSpec, type Platform } from './getPlatformSpecs.js'
import { generatePlatformFiles } from './createPlatformSpec.js'
import path from 'path'
import { prettifyDirectory } from './getCurrentDir.js'
import {
  capitalizeName,
  errorToString,
  filterDuplicateFiles,
  indent,
} from './utils.js'
import { writeFile } from './writeFile.js'
import chalk from 'chalk'
import { groupByPlatform, type SourceFile } from './syntax/SourceFile.js'
import { Logger } from './Logger.js'
import { createPodspecRubyExtension } from './autolinking/createPodspecRubyExtension.js'
import { createCMakeExtension } from './autolinking/createCMakeExtension.js'
import { createGradleExtension } from './autolinking/createGradleExtension.js'
import { createSwiftUmbrellaHeader } from './autolinking/createSwiftUmbrellaHeader.js'
import { createSwiftCxxBridge } from './autolinking/createSwiftCxxBridge.js'

interface NitrogenOptions {
  baseDirectory: string
  outputDirectory: string
}

interface NitrogenResult {
  generatedFiles: string[]
  targetSpecsCount: number
  generatedSpecsCount: number
}

export async function runNitrogen({
  baseDirectory,
  outputDirectory,
}: NitrogenOptions): Promise<NitrogenResult> {
  let targetSpecs = 0
  let generatedSpecs = 0

  // Create the TS project
  const project = new Project({
    compilerOptions: {
      strict: true,
      strictNullChecks: true,
      noUncheckedIndexedAccess: true,
    },
  })
  project.addSourceFilesAtPaths(path.join(baseDirectory, '/**/*.nitro.ts'))

  // Loop through all source files to log them
  console.log(
    chalk.reset(
      `🚀  Nitrogen runs at ${chalk.underline(prettifyDirectory(baseDirectory))}`
    )
  )
  for (const dir of project.getDirectories()) {
    const specs = dir.getSourceFiles().length
    const relativePath = prettifyDirectory(dir.getPath())
    console.log(
      `    🔍  Nitrogen found ${specs} spec${specs === 1 ? '' : 's'} in ${chalk.underline(relativePath)}`
    )
  }

  // If no source files are found, we can exit
  if (project.getSourceFiles().length === 0) {
    const searchDir = prettifyDirectory(
      path.join(path.resolve(baseDirectory), '**/*.nitro.ts')
    )
    console.log(
      `❌  Nitrogen didn't find any spec files in ${chalk.underline(searchDir)}! ` +
        `To create a Nitro Module, create a TypeScript file with the "${chalk.underline('.nitro.ts')}" suffix ` +
        'and export an interface that extends HybridObject<T>.'
    )
    process.exit()
  }

  const filesAfter: string[] = []
  const writtenFiles: SourceFile[] = []

  for (const sourceFile of project.getSourceFiles()) {
    console.log(`⏳  Parsing ${sourceFile.getBaseName()}...`)

    const startedWithSpecs = generatedSpecs

    // Find all interfaces in the given file
    const interfaces = sourceFile.getInterfaces()
    for (const module of interfaces) {
      let moduleName = '[Unknown Module]'
      try {
        // Get name of interface (= our module name)
        moduleName = module.getName()

        // Find out if it extends HybridObject
        const heritageClauses = module.getHeritageClauses()
        const platformSpecs = heritageClauses.map((clause) => {
          const types = clause.getTypeNodes()
          for (const type of types) {
            const typeName = type.getText()
            if (!typeName.startsWith('HybridObject')) {
              continue
            }
            const genericArguments = type.getTypeArguments()
            const platformSpecsArgument = genericArguments[0]
            if (
              genericArguments.length !== 1 ||
              platformSpecsArgument == null
            ) {
              throw new Error(
                `${moduleName} does not properly extend HybridObject<T> - ${typeName} does not have a single generic type argument for platform spec languages.`
              )
            }
            return getPlatformSpec(moduleName, platformSpecsArgument)
          }
          return undefined
        })
        const platformSpec = platformSpecs.find((s) => s != null)
        if (platformSpec == null) {
          // Skip this interface if it doesn't extend HybridObject
          continue
        }

        const platforms = Object.keys(platformSpec) as Platform[]
        if (platforms.length === 0) {
          console.warn(
            `⚠️   ${moduleName} does not declare any platforms in HybridObject<T> - nothing can be generated.`
          )
          continue
        }

        targetSpecs++

        console.log(
          `    ⚙️   Generating specs for HybridObject "${chalk.bold(moduleName)}"...`
        )

        // Create all files and throw it into a big lsit
        const allFiles = platforms
          .flatMap((p) => {
            const language = platformSpec[p]!
            return generatePlatformFiles(module, language)
          })
          .filter(filterDuplicateFiles)
        // Group the files by platform ({ ios: [], android: [], shared: [] })
        const filesPerPlatform = groupByPlatform(allFiles)
        // Loop through each platform one by one so that it has some kind of order (per-platform)
        for (const [p, files] of Object.entries(filesPerPlatform)) {
          const platform = p as SourceFile['platform']
          const language =
            platform === 'shared' ? 'c++' : platformSpec[platform]
          if (language == null) {
            // if the language was never specified in the spec, skip it
            continue
          }
          if (files.length === 0) {
            // if no files exist on this platform, skip it
            continue
          }

          Logger.info(
            `        ${chalk.dim(platform)}: Generating ${capitalizeName(language)} code...`
          )
          // Write the actual files for this specific platform.
          for (const file of files) {
            const basePath = path.join(
              outputDirectory,
              file.platform,
              file.language
            )
            const actualPath = await writeFile(basePath, file)
            filesAfter.push(actualPath)
            writtenFiles.push(file)
          }
        }

        // Done!
        generatedSpecs++
      } catch (error) {
        const message = indent(errorToString(error), '    ')
        console.error(
          chalk.redBright(
            `        ❌  Failed to generate spec for ${moduleName}! ${message}`
          )
        )
      }
    }

    if (generatedSpecs === startedWithSpecs) {
      console.error(
        chalk.redBright(
          `    ❌  No specs found in ${sourceFile.getBaseName()}!`
        )
      )
    }
  }

  Logger.info(`⛓️   Setting up build configs for autolinking...`)

  // iOS Podspec (Autolinking)
  const buildSetupFiles = [
    createSwiftUmbrellaHeader(),
    ...createSwiftCxxBridge(),
    createPodspecRubyExtension(),
    createCMakeExtension(writtenFiles),
    createGradleExtension(),
  ]
  for (const file of buildSetupFiles) {
    Logger.info(
      `    ${chalk.dim(file.platform)}: Creating ${file.platform} autolinking build setup...`
    )
    const basePath = path.join(outputDirectory, file.platform)
    const actualPath = await writeFile(basePath, file as unknown as SourceFile)
    filesAfter.push(actualPath)
  }

  return {
    generatedFiles: filesAfter,
    targetSpecsCount: targetSpecs,
    generatedSpecsCount: generatedSpecs,
  }
}
