import type { Language } from '../../getPlatformSpecs.js'
import { type SourceFile, type SourceImport } from '../SourceFile.js'
import type { Type, TypeKind } from './Type.js'

export class ArrayType implements Type {
  readonly itemType: Type

  constructor(itemType: Type) {
    this.itemType = itemType
  }

  get canBePassedByReference(): boolean {
    // It's a vector<..>, heavy to copy
    return true
  }

  get kind(): TypeKind {
    return 'array'
  }

  getCode(language: Language): string {
    const itemCode = this.itemType.getCode(language)

    switch (language) {
      case 'c++':
        return `std::vector<${itemCode}>`
      case 'swift':
        return `[${itemCode}]`
      case 'kotlin':
        return `Collection<${itemCode}>`
      default:
        throw new Error(
          `Language ${language} is not yet supported for ArrayType!`
        )
    }
  }
  getExtraFiles(): SourceFile[] {
    return this.itemType.getExtraFiles()
  }
  getRequiredImports(): SourceImport[] {
    return [
      {
        language: 'c++',
        name: 'vector',
        space: 'system',
      },
      ...this.itemType.getRequiredImports(),
    ]
  }
}
