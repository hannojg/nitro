import type { Language } from '../../getPlatformSpecs.js'
import { type SourceFile, type SourceImport } from '../SourceFile.js'
import type { Type, TypeKind } from './Type.js'

export class TupleType implements Type {
  readonly itemTypes: Type[]

  constructor(itemTypes: Type[]) {
    this.itemTypes = itemTypes
  }

  get canBePassedByReference(): boolean {
    // It's a tuple<..> - heavy to copy
    return true
  }

  get kind(): TypeKind {
    return 'tuple'
  }

  getCode(language: Language): string {
    const types = this.itemTypes.map((t) => t.getCode(language))

    switch (language) {
      case 'c++':
        return `std::tuple<${types.join(', ')}>`
      case 'swift':
        return `(${types.join(', ')})`
      default:
        throw new Error(
          `Language ${language} is not yet supported for TupleType!`
        )
    }
  }
  getExtraFiles(): SourceFile[] {
    return this.itemTypes.flatMap((t) => t.getExtraFiles())
  }
  getRequiredImports(): SourceImport[] {
    return [
      {
        language: 'c++',
        name: 'tuple',
        space: 'system',
      },
      ...this.itemTypes.flatMap((t) => t.getRequiredImports()),
    ]
  }
}
