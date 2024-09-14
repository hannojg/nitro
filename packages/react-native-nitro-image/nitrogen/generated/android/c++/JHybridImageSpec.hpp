///
/// HybridImageSpec.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <NitroModules/JSIConverter.hpp>
#include <NitroModules/JHybridObject.hpp>
#include <fbjni/fbjni.h>
#include "HybridImageSpec.hpp"

// Forward declaration of `ImageSize` to properly resolve imports.
namespace margelo::nitro::image { struct ImageSize; }
// Forward declaration of `PixelFormat` to properly resolve imports.
namespace margelo::nitro::image { enum class PixelFormat; }
// Forward declaration of `ImageFormat` to properly resolve imports.
namespace margelo::nitro::image { enum class ImageFormat; }

#include "ImageSize.hpp"
#include "JImageSize.hpp"
#include "PixelFormat.hpp"
#include "JPixelFormat.hpp"
#include "ImageFormat.hpp"
#include "JImageFormat.hpp"
#include <string>
#include <functional>
#include "JFunc_void_std__string.hpp"

namespace margelo::nitro::image {

  using namespace facebook;

  class JHybridImageSpec final: public jni::HybridClass<JHybridImageSpec, JHybridObject>,
                                public HybridImageSpec {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/HybridImageSpec;";
    static jni::local_ref<jhybriddata> initHybrid(jni::alias_ref<jhybridobject> jThis);
    static void registerNatives();

  private:
    // C++ constructor (called from Java via `initHybrid()`)
    explicit JHybridImageSpec(jni::alias_ref<jhybridobject> jThis) :
      HybridObject(HybridImageSpec::TAG),
      HybridBase /* JHybridObject */ (jni::static_ref_cast<JHybridObject::javaobject>(jThis)),
      _javaPart(jni::make_global(jThis)) {}

  public:
    size_t getExternalMemorySize() noexcept override;

  public:
    inline const jni::global_ref<JHybridImageSpec::javaobject>& getJavaPart() const noexcept {
      return _javaPart;
    }

  public:
    // Properties
    ImageSize getSize() override;
    PixelFormat getPixelFormat() override;
    double getSomeSettableProp() override;
    void setSomeSettableProp(double someSettableProp) override;

  public:
    // Methods
    double toArrayBuffer(ImageFormat format) override;
    void saveToFile(const std::string& path, const std::function<void(const std::string& /* path */)>& onFinished) override;

  public:
    // Properties (overriden by JNI)
    jni::local_ref<JImageSize> getSizeJNI();
    jni::local_ref<JPixelFormat> getPixelFormatJNI();
    double getSomeSettablePropJNI();
    void setSomeSettablePropJNI(double someSettableProp);

  public:
    // Methods (overriden by JNI)
    double toArrayBufferJNI(const jni::local_ref<JImageFormat>& format);
    void saveToFileJNI(const jni::local_ref<jni::JString>& path, const jni::local_ref<JFunc_void_std__string::javaobject>& onFinished);

  protected:
    // Override prototype to use JNI methods
    void loadHybridMethods() override;

  private:
    friend HybridBase;
    using HybridBase::HybridBase;
    jni::global_ref<JHybridImageSpec::javaobject> _javaPart;
  };

} // namespace margelo::nitro::image

namespace margelo::nitro {

  // NativeState<{}> <> JHybridImageSpec
  template <>
  struct JSIConverter<JHybridImageSpec::javaobject> final {
    static inline jni::local_ref<JHybridImageSpec::javaobject> fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object object = arg.asObject(runtime);
      if (!object.hasNativeState<JHybridObject>(runtime)) [[unlikely]] {
        std::string typeDescription = arg.toString(runtime).utf8(runtime);
        throw std::runtime_error("Cannot convert \"" + typeDescription + "\" to JHybridObject! It does not have a NativeState.");
      }
      std::shared_ptr<jsi::NativeState> nativeState = object.getNativeState(runtime);
      std::shared_ptr<JHybridImageSpec> jhybridObject = std::dynamic_pointer_cast<JHybridImageSpec>(nativeState);
      return jni::make_local(jhybridObject->getJavaPart());
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const jni::local_ref<JHybridImageSpec::javaobject>& arg) {
      return arg->cthis()->toObject(runtime);
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object object = value.getObject(runtime);
      return object.hasNativeState<JHybridImageSpec>(runtime);
    }
  };

} // namespace margelo::nitro
