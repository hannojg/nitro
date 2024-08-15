import { escapeCppName, toReferenceType } from '../helpers.js'
import type { SourceImport } from '../SourceFile.js'
import { VariantType } from '../types/VariantType.js'
import { ArrayType } from '../types/ArrayType.js'
import { FunctionType } from '../types/FunctionType.js'
import { getTypeAs } from '../types/getTypeAs.js'
import { OptionalType } from '../types/OptionalType.js'
import { RecordType } from '../types/RecordType.js'
import type { Type } from '../types/Type.js'
import { TupleType } from '../types/TupleType.js'
import { escapeComments } from '../../utils.js'

export interface SwiftCxxHelper {
  cxxCode: string
  funcName: string
  specializationName: string
  requiredIncludes: SourceImport[]
}

export function createSwiftCxxHelpers(type: Type): SwiftCxxHelper | undefined {
  switch (type.kind) {
    case 'optional':
      return createCxxOptionalSwiftHelper(getTypeAs(type, OptionalType))
    case 'array':
      return createCxxVectorSwiftHelper(getTypeAs(type, ArrayType))
    case 'record':
      return createCxxUnorderedMapSwiftHelper(getTypeAs(type, RecordType))
    case 'function':
      return createCxxFunctionSwiftHelper(getTypeAs(type, FunctionType))
    case 'variant':
      return createCxxVariantSwiftHelper(getTypeAs(type, VariantType))
    case 'tuple':
      return createCxxTupleSwiftHelper(getTypeAs(type, TupleType))
    default:
      return undefined
  }
}

/**
 * Creates a C++ `create_optional<T>(value)` function that can be called from Swift.
 */
function createCxxOptionalSwiftHelper(type: OptionalType): SwiftCxxHelper {
  const actualType = type.getCode('c++')
  const name = escapeCppName(type.getCode('c++'))
  return {
    funcName: `create_${name}`,
    specializationName: name,
    requiredIncludes: [
      {
        name: 'optional',
        space: 'system',
        language: 'c++',
      },
      ...type.getRequiredImports(),
    ],
    cxxCode: `
/**
 * Specialized version of \`${escapeComments(actualType)}\`.
 */
using ${name} = ${actualType};
inline ${actualType} create_${name}(const ${type.wrappingType.getCode('c++')}& value) {
  return ${actualType}(value);
}
    `.trim(),
  }
}

/**
 * Creates a C++ `create_vector_T<T>(size)` function that can be called from Swift.
 */
function createCxxVectorSwiftHelper(type: ArrayType): SwiftCxxHelper {
  const actualType = type.getCode('c++')
  const name = escapeCppName(type.getCode('c++'))
  return {
    funcName: `create_${name}`,
    specializationName: name,
    requiredIncludes: [
      {
        name: 'vector',
        space: 'system',
        language: 'c++',
      },
      ...type.getRequiredImports(),
    ],
    cxxCode: `
/**
 * Specialized version of \`${escapeComments(actualType)}\`.
 */
using ${name} = ${actualType};
inline ${actualType} create_${name}(size_t size) {
  ${actualType} vector;
  vector.reserve(size);
  return vector;
}
    `.trim(),
  }
}

/**
 * Creates a C++ `makeUnorderedMap<T>(size)` function that can be called from Swift.
 */
function createCxxUnorderedMapSwiftHelper(type: RecordType): SwiftCxxHelper {
  const actualType = type.getCode('c++')
  const keyType = type.keyType.getCode('c++')
  const name = escapeCppName(type.getCode('c++'))
  return {
    funcName: `create_${name}`,
    specializationName: name,
    requiredIncludes: [
      {
        name: 'unordered_map',
        space: 'system',
        language: 'c++',
      },
      ...type.getRequiredImports(),
    ],
    cxxCode: `
/**
 * Specialized version of \`${escapeComments(actualType)}\`.
 */
using ${name} = ${actualType};
inline ${actualType} create_${name}(size_t size) {
  ${actualType} map;
  map.reserve(size);
  return map;
}
inline std::vector<${keyType}> get_${name}_keys(const ${name}& map) {
  std::vector<${keyType}> keys;
  keys.reserve(map.size());
  for (const auto& entry : map) {
    keys.push_back(entry.first);
  }
  return keys;
}
    `.trim(),
  }
}

/**
 * Creates a C++ `Func_XXXXX` specialization that can be used from Swift.
 */
function createCxxFunctionSwiftHelper(type: FunctionType): SwiftCxxHelper {
  const actualType = type.getCode('c++')
  const params = type.parameters.map((p) =>
    p.canBePassedByReference
      ? toReferenceType(p.getCode('c++'))
      : p.getCode('c++')
  )
  const cfuncParams = ['void* /* context */', ...params]
  const returnType = type.returnType.getCode('c++')
  const functionPointerParam = `${returnType}(*func)(${cfuncParams.join(', ')})`
  const boundArgs = [
    'context',
    ...type.parameters.map((_, i) => `std::placeholders::_${i + 1}`),
  ]

  const name = type.specializationName
  return {
    funcName: `create_${name}`,
    specializationName: name,
    requiredIncludes: [
      {
        name: 'functional',
        space: 'system',
        language: 'c++',
      },
      ...type.getRequiredImports(),
    ],
    cxxCode: `
/**
 * Specialized version of \`${escapeComments(actualType)}\`.
 */
using ${name} = ${actualType};
inline ${name} create_${name}(${functionPointerParam}, void* context) {
  return std::bind(func, ${boundArgs.join(', ')});
}
    `.trim(),
  }
}

/**
 * Creates multiple C++ `create_variant_A_B_C<A, B, C>(A...)` functions that can be called from Swift.
 */
function createCxxVariantSwiftHelper(type: VariantType): SwiftCxxHelper {
  const actualType = type.getCode('c++')
  const name = escapeCppName(type.getCode('c++'))
  const createFunctions = type.variants
    .map((t) => {
      const param = t.canBePassedByReference
        ? toReferenceType(t.getCode('c++'))
        : t.getCode('c++')
      return `
inline ${actualType} create_${name}(${param} value) {
  return value;
}
      `.trim()
    })
    .join('\n')
  const getFunctions = type.variants
    .map((t, i) => {
      return `
inline ${t.getCode('c++')} get_${name}_${i}(const ${actualType}& variant) {
  return std::get<${i}>(variant);
}
      `.trim()
    })
    .join('\n')
  return {
    funcName: `create_${name}`,
    specializationName: name,
    requiredIncludes: [
      {
        name: 'variant',
        space: 'system',
        language: 'c++',
      },
      ...type.getRequiredImports(),
    ],
    cxxCode: `
/**
 * Specialized version of \`${escapeComments(actualType)}\`.
 */
using ${name} = ${actualType};
${createFunctions}
${getFunctions}
      `.trim(),
  }
}

/**
 * Creates a C++ `create_tuple_A_B_C<A, B, C>(A, B, C)` function that can be called from Swift.
 */
function createCxxTupleSwiftHelper(type: TupleType): SwiftCxxHelper {
  const actualType = type.getCode('c++')
  const name = escapeCppName(type.getCode('c++'))
  const typesSignature = type.itemTypes
    .map((t, i) => {
      const code = t.getCode('c++')
      return `${t.canBePassedByReference ? toReferenceType(code) : code} arg${i}`
    })
    .join(', ')
  const typesForward = type.itemTypes.map((_t, i) => `arg${i}`).join(', ')
  return {
    funcName: `create_${name}`,
    specializationName: name,
    requiredIncludes: [
      {
        name: 'tuple',
        space: 'system',
        language: 'c++',
      },
      ...type.getRequiredImports(),
    ],
    cxxCode: `
/**
 * Specialized version of \`${escapeComments(actualType)}\`.
 */
using ${name} = ${actualType};
inline ${actualType} create_${name}(${typesSignature}) {
  return ${actualType} { ${typesForward} };
}
     `.trim(),
  }
}
