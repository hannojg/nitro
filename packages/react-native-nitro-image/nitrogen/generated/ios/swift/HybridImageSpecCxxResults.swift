///
/// HybridImageSpecCxxResults.swift
/// Thu Aug 08 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

/**
 * C++ does not support catching Swift errors yet, so we have to wrap
 * them in a Result type.
 * - .value means the function returned successfully (either a value, or void)
 * - .error means the function threw any Error. Only the message can be propagated
 *
 * HybridImageSpecCxx will then wrap all calls to HybridImageSpec
 * to properly catch Swift errors and return either .value or .error to C++.
 */

import NitroModules

/**
 * The exception-free result type for HybridImageSpec.toArrayBuffer(...).
 * Original func:
 * ```swift
 * func toArrayBuffer(format: margelo.nitro.image.ImageFormat) throws -> Double
 * ```
 * - seealso: `HybridImageSpec.toArrayBuffer(format:)`
 */
@frozen
public enum HybridImageSpecCxx_toArrayBuffer_Result {
  case value(Double)
  case error(message: String)
}

/**
 * The exception-free result type for HybridImageSpec.saveToFile(...).
 * Original func:
 * ```swift
 * func saveToFile(path: String, onFinished: margelo.nitro.image.Func_void_std__string) throws -> Void
 * ```
 * - seealso: `HybridImageSpec.saveToFile(path:, onFinished:)`
 */
@frozen
public enum HybridImageSpecCxx_saveToFile_Result {
  case value
  case error(message: String)
}
