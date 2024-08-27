package com.margelo.nitro.core

import androidx.annotation.Keep
import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip

/**
 * Represents an untyped map of string keys with associated values.
 * This is like an "`any`" JS object.
 */
@Suppress("KotlinJniMissingFunction")
@Keep
@DoNotStrip
class AnyMap {
  private val mHybridData: HybridData

  /**
   * Create a new empty `AnyMap`.
   */
  constructor() {
    mHybridData = initHybrid()
  }

  /**
   * Create a new `AnyMap` from C++, which potentially already holds data.
   */
  @Suppress("unused")
  private constructor(hybridData: HybridData) {
    mHybridData = hybridData
  }


  external fun contains(key: String): Boolean
  external fun remove(key: String)
  external fun clear()

  external fun isNull(key: String): Boolean
  external fun isDouble(key: String): Boolean
  external fun isBoolean(key: String): Boolean
  external fun isBigInt(key: String): Boolean
  external fun isString(key: String): Boolean
  external fun isArray(key: String): Boolean
  external fun isObject(key: String): Boolean

  external fun getDouble(key: String): Double
  external fun getBoolean(key: String): Boolean
  external fun getBigInt(key: String): Long
  external fun getString(key: String): String

  external fun setNull(key: String)
  external fun setDouble(key: String, value: Double)
  external fun setBoolean(key: String, value: Boolean)
  external fun setBigInt(key: String, value: Long)
  external fun setString(key: String, value: String)

  private external fun initHybrid(): HybridData
}
