///
/// JHybridImageFactorySpec.cpp
/// Mon Aug 19 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridImageFactorySpec.hpp"

// Forward declaration of `HybridImageSpec` to properly resolve imports.
namespace margelo::nitro::image { class HybridImageSpec; }

#include "memory"
#include "HybridImageSpec.hpp"
#include "JHybridImageSpec.hpp"
#include "string"

namespace margelo::nitro::image {

  jni::local_ref<JHybridImageFactorySpec::jhybriddata> JHybridImageFactorySpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridImageFactorySpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridImageFactorySpec::initHybrid),
    });
  }

  size_t JHybridImageFactorySpec::getExternalMemorySize() noexcept {
    static const auto method = _javaPart->getClass()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart.get());
  }

  // Properties
  

  // Methods
  std::shared_ptr<margelo::nitro::image::HybridImageSpec> JHybridImageFactorySpec::loadImageFromFile(const std::string& path) {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<JHybridImageSpec::javaobject>(std::string)>("loadImageFromFile");
    auto result = method(_javaPart, path);
    throw std::runtime_error("Cannot convert HybridImageSpec yet!");
  }
  std::shared_ptr<margelo::nitro::image::HybridImageSpec> JHybridImageFactorySpec::loadImageFromURL(const std::string& path) {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<JHybridImageSpec::javaobject>(std::string)>("loadImageFromURL");
    auto result = method(_javaPart, path);
      throw std::runtime_error("Cannot convert HybridImageSpec yet!");
  }
  std::shared_ptr<margelo::nitro::image::HybridImageSpec> JHybridImageFactorySpec::loadImageFromSystemName(const std::string& path) {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<JHybridImageSpec::javaobject>(std::string)>("loadImageFromSystemName");
    auto result = method(_javaPart, path);
      throw std::runtime_error("Cannot convert HybridImageSpec yet!");
  }
  std::shared_ptr<margelo::nitro::image::HybridImageSpec> JHybridImageFactorySpec::bounceBack(const std::shared_ptr<margelo::nitro::image::HybridImageSpec>& image) {
    static const auto method = _javaPart->getClass()->getMethod<jni::alias_ref<JHybridImageSpec::javaobject>(jni::alias_ref<JHybridImageSpec::javaobject>)>("bounceBack");
      throw std::runtime_error("Cannot convert HybridImageSpec yet!");
  }

} // namespace margelo::nitro::image
