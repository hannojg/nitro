import { NitroConfig } from '../../config/NitroConfig.js'
import type { Language } from '../../getPlatformSpecs.js'
import {
  createCppFunctionSpecialization,
  type FunctionSpecialization,
} from '../c++/CppFunctionSpecialization.js'
import { Parameter } from '../Parameter.js'
import { type SourceFile, type SourceImport } from '../SourceFile.js'
import { PromiseType } from './PromiseType.js'
import type { NamedType, Type, TypeKind } from './Type.js'

export class FunctionType implements Type {
  readonly returnType: Type
  readonly parameters: NamedType[]

  constructor(returnType: Type, parameters: NamedType[]) {
    if (returnType.kind === 'void') {
      // void callbacks are async, but we don't care about the result.
      this.returnType = returnType
    } else {
      // non-void callbacks are async and need to be awaited to get the result from JS.
      this.returnType = new PromiseType(returnType)
    }
    this.parameters = parameters
  }

  get canBePassedByReference(): boolean {
    // It's a function<..>, heavy to copy.
    return true
  }

  get kind(): TypeKind {
    return 'function'
  }

  get specialization(): FunctionSpecialization {
    return createCppFunctionSpecialization(this)
  }

  /**
   * For a function, get the forward recreation of it:
   * If variable is called `func`, this would return:
   * ```cpp
   * [func = std::move(func)](Params... params) -> ReturnType {
   *   return func(params...);
   * }
   * ```
   */
  getForwardRecreationCode(variableName: string, language: Language): string {
    const returnType = this.returnType.getCode(language)
    const parameters = this.parameters
      .map((p) => new Parameter(p.name, p))
      .map((p) => p.getCode('c++'))
    const forwardedParameters = this.parameters.map(
      (p) => `std::forward<decltype(${p.name})>(${p.name})`
    )

    switch (language) {
      case 'c++':
        const closure = `[${variableName} = std::move(${variableName})]`
        const signature = `(${parameters.join(', ')}) -> ${returnType}`
        const body = `{ return ${variableName}(${forwardedParameters.join(', ')}); }`
        return `${closure} ${signature} ${body}`
      default:
        throw new Error(
          `Language ${language} is not yet supported for function forward recreations!`
        )
    }
  }

  getCode(language: Language): string {
    const specialization = this.specialization

    switch (language) {
      case 'c++':
        return specialization.typename
      case 'swift':
        return NitroConfig.getCxxNamespace('swift', specialization.typename)
      case 'kotlin':
        return NitroConfig.getAndroidPackage(
          'java/kotlin',
          specialization.typename
        )
      default:
        throw new Error(
          `Language ${language} is not yet supported for FunctionType!`
        )
    }
  }
  getExtraFiles(): SourceFile[] {
    const specialization = this.specialization
    return [
      specialization.declarationFile,
      ...this.returnType.getExtraFiles(),
      ...this.parameters.flatMap((p) => p.getExtraFiles()),
    ]
  }
  getRequiredImports(): SourceImport[] {
    return [
      {
        language: 'c++',
        name: this.specialization.declarationFile.name,
        forwardDeclaration: undefined,
        space: 'user',
      },
      ...this.returnType.getRequiredImports(),
      ...this.parameters.flatMap((p) => p.getRequiredImports()),
    ]
  }
}
