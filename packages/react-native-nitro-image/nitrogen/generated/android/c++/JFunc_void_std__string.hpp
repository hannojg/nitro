///
/// JFunc_void_std__string.hpp
/// Tue Aug 06 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "Func_void_std__string.hpp"

namespace margelo::nitro::image {

  using namespace facebook;

  /**
   * C++ representation of the callback Func_void_std__string.
   * This is a Kotlin `(path: String) -> Unit`, backed by a `std::function<...>`.
   */
  struct JFunc_void_std__string: public jni::HybridClass<JFunc_void_std__string> {
  public:
    static jni::local_ref<JFunc_void_std__string::javaobject> create(const Func_void_std__string& func) {
      return JFunc_void_std__string::newObjectCxxArgs(func);
    }

  public:
    void call(const std::string& path) {
      return _func(path);
    }

  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/Func_void_std__string;";
    static void registerNatives() {
      registerHybrid({makeNativeMethod("call", JFunc_void_std__string::call)});
    }

  private:
    explicit JFunc_void_std__string(const Func_void_std__string& func): _func(func) { }

  private:
    friend HybridBase;
    Func_void_std__string _func;
  };

} // namespace margelo::nitro::image
