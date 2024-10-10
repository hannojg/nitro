///
/// JHybridTestObjectSwiftKotlinSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "JHybridTestObjectSwiftKotlinSpec.hpp"

// Forward declaration of `HybridTestObjectSwiftKotlinSpec` to properly resolve imports.
namespace margelo::nitro::image { class HybridTestObjectSwiftKotlinSpec; }
// Forward declaration of `AnyMap` to properly resolve imports.
namespace NitroModules { class AnyMap; }
// Forward declaration of `Powertrain` to properly resolve imports.
namespace margelo::nitro::image { enum class Powertrain; }
// Forward declaration of `Car` to properly resolve imports.
namespace margelo::nitro::image { struct Car; }
// Forward declaration of `Person` to properly resolve imports.
namespace margelo::nitro::image { struct Person; }
// Forward declaration of `ArrayBuffer` to properly resolve imports.
namespace NitroModules { class ArrayBuffer; }
// Forward declaration of `HybridChildSpec` to properly resolve imports.
namespace margelo::nitro::image { class HybridChildSpec; }
// Forward declaration of `HybridBaseSpec` to properly resolve imports.
namespace margelo::nitro::image { class HybridBaseSpec; }

#include <memory>
#include "HybridTestObjectSwiftKotlinSpec.hpp"
#include "JHybridTestObjectSwiftKotlinSpec.hpp"
#include <NitroModules/JNISharedPtr.hpp>
#include <string>
#include <optional>
#include <variant>
#include "JVariant_String_Double.hpp"
#include <vector>
#include <NitroModules/AnyMap.hpp>
#include <NitroModules/JAnyMap.hpp>
#include "Powertrain.hpp"
#include "JPowertrain.hpp"
#include <future>
#include <NitroModules/JPromise.hpp>
#include "Car.hpp"
#include "JCar.hpp"
#include "Person.hpp"
#include "JPerson.hpp"
#include <NitroModules/ArrayBuffer.hpp>
#include <NitroModules/JArrayBuffer.hpp>
#include "HybridChildSpec.hpp"
#include "JHybridChildSpec.hpp"
#include "HybridBaseSpec.hpp"
#include "JHybridBaseSpec.hpp"
#include <functional>
#include "JFunc_void.hpp"
#include "JFunc_void_std__optional_double_.hpp"

namespace margelo::nitro::image {

  jni::local_ref<JHybridTestObjectSwiftKotlinSpec::jhybriddata> JHybridTestObjectSwiftKotlinSpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridTestObjectSwiftKotlinSpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridTestObjectSwiftKotlinSpec::initHybrid),
    });
  }

  size_t JHybridTestObjectSwiftKotlinSpec::getExternalMemorySize() noexcept {
    static const auto method = _javaPart->getClass()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  std::shared_ptr<margelo::nitro::image::HybridTestObjectSwiftKotlinSpec> JHybridTestObjectSwiftKotlinSpec::getThisObject() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridTestObjectSwiftKotlinSpec::javaobject>()>("getThisObject");
    auto __result = method(_javaPart);
    return JNISharedPtr::make_shared_from_jni<JHybridTestObjectSwiftKotlinSpec>(jni::make_global(__result));
  }
  double JHybridTestObjectSwiftKotlinSpec::getNumberValue() {
    static const auto method = _javaPart->getClass()->getMethod<double()>("getNumberValue");
    auto __result = method(_javaPart);
    return __result;
  }
  void JHybridTestObjectSwiftKotlinSpec::setNumberValue(double numberValue) {
    static const auto method = _javaPart->getClass()->getMethod<void(double /* numberValue */)>("setNumberValue");
    method(_javaPart, numberValue);
  }
  bool JHybridTestObjectSwiftKotlinSpec::getBoolValue() {
    static const auto method = _javaPart->getClass()->getMethod<jboolean()>("getBoolValue");
    auto __result = method(_javaPart);
    return __result;
  }
  void JHybridTestObjectSwiftKotlinSpec::setBoolValue(bool boolValue) {
    static const auto method = _javaPart->getClass()->getMethod<void(jboolean /* boolValue */)>("setBoolValue");
    method(_javaPart, boolValue);
  }
  std::string JHybridTestObjectSwiftKotlinSpec::getStringValue() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JString>()>("getStringValue");
    auto __result = method(_javaPart);
    return __result->toStdString();
  }
  void JHybridTestObjectSwiftKotlinSpec::setStringValue(const std::string& stringValue) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JString> /* stringValue */)>("setStringValue");
    method(_javaPart, jni::make_jstring(stringValue));
  }
  int64_t JHybridTestObjectSwiftKotlinSpec::getBigintValue() {
    static const auto method = _javaPart->getClass()->getMethod<int64_t()>("getBigintValue");
    auto __result = method(_javaPart);
    return __result;
  }
  void JHybridTestObjectSwiftKotlinSpec::setBigintValue(int64_t bigintValue) {
    static const auto method = _javaPart->getClass()->getMethod<void(int64_t /* bigintValue */)>("setBigintValue");
    method(_javaPart, bigintValue);
  }
  std::optional<std::string> JHybridTestObjectSwiftKotlinSpec::getStringOrUndefined() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JString>()>("getStringOrUndefined");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->toStdString()) : std::nullopt;
  }
  void JHybridTestObjectSwiftKotlinSpec::setStringOrUndefined(const std::optional<std::string>& stringOrUndefined) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JString> /* stringOrUndefined */)>("setStringOrUndefined");
    method(_javaPart, stringOrUndefined.has_value() ? jni::make_jstring(stringOrUndefined.value()) : nullptr);
  }
  std::optional<std::string> JHybridTestObjectSwiftKotlinSpec::getStringOrNull() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JString>()>("getStringOrNull");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->toStdString()) : std::nullopt;
  }
  void JHybridTestObjectSwiftKotlinSpec::setStringOrNull(const std::optional<std::string>& stringOrNull) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JString> /* stringOrNull */)>("setStringOrNull");
    method(_javaPart, stringOrNull.has_value() ? jni::make_jstring(stringOrNull.value()) : nullptr);
  }
  std::optional<std::string> JHybridTestObjectSwiftKotlinSpec::getOptionalString() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JString>()>("getOptionalString");
    auto __result = method(_javaPart);
    return __result != nullptr ? std::make_optional(__result->toStdString()) : std::nullopt;
  }
  void JHybridTestObjectSwiftKotlinSpec::setOptionalString(const std::optional<std::string>& optionalString) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JString> /* optionalString */)>("setOptionalString");
    method(_javaPart, optionalString.has_value() ? jni::make_jstring(optionalString.value()) : nullptr);
  }
  std::variant<std::string, double> JHybridTestObjectSwiftKotlinSpec::getSomeVariant() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JVariant_String_Double>()>("getSomeVariant");
    auto __result = method(_javaPart);
    return __result->toCpp();
  }
  void JHybridTestObjectSwiftKotlinSpec::setSomeVariant(const std::variant<std::string, double>& someVariant) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<JVariant_String_Double> /* someVariant */)>("setSomeVariant");
    method(_javaPart, JVariant_String_Double::fromCpp(someVariant));
  }

  // Methods
  std::shared_ptr<margelo::nitro::image::HybridTestObjectSwiftKotlinSpec> JHybridTestObjectSwiftKotlinSpec::newTestObject() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridTestObjectSwiftKotlinSpec::javaobject>()>("newTestObject");
    auto __result = method(_javaPart);
    return JNISharedPtr::make_shared_from_jni<JHybridTestObjectSwiftKotlinSpec>(jni::make_global(__result));
  }
  void JHybridTestObjectSwiftKotlinSpec::simpleFunc() {
    static const auto method = _javaPart->getClass()->getMethod<void()>("simpleFunc");
    method(_javaPart);
  }
  double JHybridTestObjectSwiftKotlinSpec::addNumbers(double a, double b) {
    static const auto method = _javaPart->getClass()->getMethod<double(double /* a */, double /* b */)>("addNumbers");
    auto __result = method(_javaPart, a, b);
    return __result;
  }
  std::string JHybridTestObjectSwiftKotlinSpec::addStrings(const std::string& a, const std::string& b) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JString>(jni::alias_ref<jni::JString> /* a */, jni::alias_ref<jni::JString> /* b */)>("addStrings");
    auto __result = method(_javaPart, jni::make_jstring(a), jni::make_jstring(b));
    return __result->toStdString();
  }
  void JHybridTestObjectSwiftKotlinSpec::multipleArguments(double num, const std::string& str, bool boo) {
    static const auto method = _javaPart->getClass()->getMethod<void(double /* num */, jni::alias_ref<jni::JString> /* str */, jboolean /* boo */)>("multipleArguments");
    method(_javaPart, num, jni::make_jstring(str), boo);
  }
  std::vector<std::string> JHybridTestObjectSwiftKotlinSpec::bounceStrings(const std::vector<std::string>& array) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JArrayClass<jni::JString>>(jni::alias_ref<jni::JArrayClass<jni::JString>> /* array */)>("bounceStrings");
    auto __result = method(_javaPart, [&]() {
      size_t __size = array.size();
      jni::local_ref<jni::JArrayClass<jni::JString>> __array = jni::JArrayClass<jni::JString>::newArray(__size);
      for (size_t i = 0; i < __size; i++) {
        const auto& element = array[i];
        __array->setElement(i, *jni::make_jstring(element));
      }
      return __array;
    }());
    return [&]() {
      size_t __size = __result->size();
      std::vector<std::string> __vector;
      __vector.reserve(__size);
      for (size_t i = 0; i < __size; i++) {
        auto __element = __result->getElement(i);
        __vector.push_back(__element->toStdString());
      }
      return __vector;
    }();
  }
  std::vector<double> JHybridTestObjectSwiftKotlinSpec::bounceNumbers(const std::vector<double>& array) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JArrayDouble>(jni::alias_ref<jni::JArrayDouble> /* array */)>("bounceNumbers");
    auto __result = method(_javaPart, [&]() {
      size_t __size = array.size();
      jni::local_ref<jni::JArrayDouble> __array = jni::JArrayDouble::newArray(__size);
      __array->setRegion(0, __size, array.data());
      return __array;
    }());
    return [&]() {
      size_t __size = __result->size();
      std::vector<double> __vector;
      __vector.reserve(__size);
      __result->getRegion(0, __size, __vector.data());
      return __vector;
    }();
  }
  std::shared_ptr<AnyMap> JHybridTestObjectSwiftKotlinSpec::createMap() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JAnyMap::javaobject>()>("createMap");
    auto __result = method(_javaPart);
    return __result->cthis()->getMap();
  }
  std::shared_ptr<AnyMap> JHybridTestObjectSwiftKotlinSpec::mapRoundtrip(const std::shared_ptr<AnyMap>& map) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JAnyMap::javaobject>(jni::alias_ref<JAnyMap::javaobject> /* map */)>("mapRoundtrip");
    auto __result = method(_javaPart, JAnyMap::create(map));
    return __result->cthis()->getMap();
  }
  double JHybridTestObjectSwiftKotlinSpec::funcThatThrows() {
    static const auto method = _javaPart->getClass()->getMethod<double()>("funcThatThrows");
    auto __result = method(_javaPart);
    return __result;
  }
  std::string JHybridTestObjectSwiftKotlinSpec::tryOptionalParams(double num, bool boo, const std::optional<std::string>& str) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JString>(double /* num */, jboolean /* boo */, jni::alias_ref<jni::JString> /* str */)>("tryOptionalParams");
    auto __result = method(_javaPart, num, boo, str.has_value() ? jni::make_jstring(str.value()) : nullptr);
    return __result->toStdString();
  }
  std::string JHybridTestObjectSwiftKotlinSpec::tryMiddleParam(double num, std::optional<bool> boo, const std::string& str) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<jni::JString>(double /* num */, jni::alias_ref<jni::JBoolean> /* boo */, jni::alias_ref<jni::JString> /* str */)>("tryMiddleParam");
    auto __result = method(_javaPart, num, boo.has_value() ? jni::JBoolean::valueOf(boo.value()) : nullptr, jni::make_jstring(str));
    return __result->toStdString();
  }
  std::optional<Powertrain> JHybridTestObjectSwiftKotlinSpec::tryOptionalEnum(std::optional<Powertrain> value) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JPowertrain>(jni::alias_ref<JPowertrain> /* value */)>("tryOptionalEnum");
    auto __result = method(_javaPart, value.has_value() ? JPowertrain::fromCpp(value.value()) : nullptr);
    return __result != nullptr ? std::make_optional(__result->toCpp()) : std::nullopt;
  }
  int64_t JHybridTestObjectSwiftKotlinSpec::calculateFibonacciSync(double value) {
    static const auto method = _javaPart->getClass()->getMethod<int64_t(double /* value */)>("calculateFibonacciSync");
    auto __result = method(_javaPart, value);
    return __result;
  }
  std::future<int64_t> JHybridTestObjectSwiftKotlinSpec::calculateFibonacciAsync(double value) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JPromise::javaobject>(double /* value */)>("calculateFibonacciAsync");
    auto __result = method(_javaPart, value);
    return [&]() {
      auto __promise = std::make_shared<std::promise<int64_t>>();
      __result->cthis()->addOnResolvedListener([=](const jni::alias_ref<jni::JObject>& __boxedResult) {
        auto __result = jni::static_ref_cast<jni::JLong>(__boxedResult);
        __promise->set_value(__result->value());
      });
      __result->cthis()->addOnRejectedListener([=](const jni::alias_ref<jni::JString>& __message) {
        std::runtime_error __error(__message->toStdString());
        __promise->set_exception(std::make_exception_ptr(__error));
      });
      return __promise->get_future();
    }();
  }
  std::future<void> JHybridTestObjectSwiftKotlinSpec::wait(double seconds) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JPromise::javaobject>(double /* seconds */)>("wait");
    auto __result = method(_javaPart, seconds);
    return [&]() {
      auto __promise = std::make_shared<std::promise<void>>();
      __result->cthis()->addOnResolvedListener([=](const jni::alias_ref<jni::JObject>& __boxedResult) {
        __promise->set_value();
      });
      __result->cthis()->addOnRejectedListener([=](const jni::alias_ref<jni::JString>& __message) {
        std::runtime_error __error(__message->toStdString());
        __promise->set_exception(std::make_exception_ptr(__error));
      });
      return __promise->get_future();
    }();
  }
  void JHybridTestObjectSwiftKotlinSpec::callCallback(const std::function<void()>& callback) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<JFunc_void::javaobject> /* callback */)>("callCallback");
    method(_javaPart, JFunc_void::fromCpp(callback));
  }
  void JHybridTestObjectSwiftKotlinSpec::callAll(const std::function<void()>& first, const std::function<void()>& second, const std::function<void()>& third) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<JFunc_void::javaobject> /* first */, jni::alias_ref<JFunc_void::javaobject> /* second */, jni::alias_ref<JFunc_void::javaobject> /* third */)>("callAll");
    method(_javaPart, JFunc_void::fromCpp(first), JFunc_void::fromCpp(second), JFunc_void::fromCpp(third));
  }
  void JHybridTestObjectSwiftKotlinSpec::callWithOptional(std::optional<double> value, const std::function<void(std::optional<double> /* maybe */)>& callback) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<jni::JDouble> /* value */, jni::alias_ref<JFunc_void_std__optional_double_::javaobject> /* callback */)>("callWithOptional");
    method(_javaPart, value.has_value() ? jni::JDouble::valueOf(value.value()) : nullptr, JFunc_void_std__optional_double_::fromCpp(callback));
  }
  Car JHybridTestObjectSwiftKotlinSpec::getCar() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JCar>()>("getCar");
    auto __result = method(_javaPart);
    return __result->toCpp();
  }
  bool JHybridTestObjectSwiftKotlinSpec::isCarElectric(const Car& car) {
    static const auto method = _javaPart->getClass()->getMethod<jboolean(jni::alias_ref<JCar> /* car */)>("isCarElectric");
    auto __result = method(_javaPart, JCar::fromCpp(car));
    return __result;
  }
  std::optional<Person> JHybridTestObjectSwiftKotlinSpec::getDriver(const Car& car) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JPerson>(jni::alias_ref<JCar> /* car */)>("getDriver");
    auto __result = method(_javaPart, JCar::fromCpp(car));
    return __result != nullptr ? std::make_optional(__result->toCpp()) : std::nullopt;
  }
  std::shared_ptr<ArrayBuffer> JHybridTestObjectSwiftKotlinSpec::createArrayBuffer() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JArrayBuffer::javaobject>()>("createArrayBuffer");
    auto __result = method(_javaPart);
    return __result->cthis()->getArrayBuffer();
  }
  double JHybridTestObjectSwiftKotlinSpec::getBufferLastItem(const std::shared_ptr<ArrayBuffer>& buffer) {
    static const auto method = _javaPart->getClass()->getMethod<double(jni::alias_ref<JArrayBuffer::javaobject> /* buffer */)>("getBufferLastItem");
    auto __result = method(_javaPart, JArrayBuffer::wrap(buffer));
    return __result;
  }
  void JHybridTestObjectSwiftKotlinSpec::setAllValuesTo(const std::shared_ptr<ArrayBuffer>& buffer, double value) {
    static const auto method = _javaPart->getClass()->getMethod<void(jni::alias_ref<JArrayBuffer::javaobject> /* buffer */, double /* value */)>("setAllValuesTo");
    method(_javaPart, JArrayBuffer::wrap(buffer), value);
  }
  std::shared_ptr<margelo::nitro::image::HybridChildSpec> JHybridTestObjectSwiftKotlinSpec::createChild() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridChildSpec::javaobject>()>("createChild");
    auto __result = method(_javaPart);
    return JNISharedPtr::make_shared_from_jni<JHybridChildSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridBaseSpec> JHybridTestObjectSwiftKotlinSpec::createBase() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridBaseSpec::javaobject>()>("createBase");
    auto __result = method(_javaPart);
    return JNISharedPtr::make_shared_from_jni<JHybridBaseSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridBaseSpec> JHybridTestObjectSwiftKotlinSpec::createBaseActualChild() {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridBaseSpec::javaobject>()>("createBaseActualChild");
    auto __result = method(_javaPart);
    return JNISharedPtr::make_shared_from_jni<JHybridBaseSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridChildSpec> JHybridTestObjectSwiftKotlinSpec::bounceChild(const std::shared_ptr<margelo::nitro::image::HybridChildSpec>& child) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridChildSpec::javaobject>(jni::alias_ref<JHybridChildSpec::javaobject> /* child */)>("bounceChild");
    auto __result = method(_javaPart, std::dynamic_pointer_cast<JHybridChildSpec>(child)->getJavaPart());
    return JNISharedPtr::make_shared_from_jni<JHybridChildSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridBaseSpec> JHybridTestObjectSwiftKotlinSpec::bounceBase(const std::shared_ptr<margelo::nitro::image::HybridBaseSpec>& base) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridBaseSpec::javaobject>(jni::alias_ref<JHybridBaseSpec::javaobject> /* base */)>("bounceBase");
    auto __result = method(_javaPart, std::dynamic_pointer_cast<JHybridBaseSpec>(base)->getJavaPart());
    return JNISharedPtr::make_shared_from_jni<JHybridBaseSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridBaseSpec> JHybridTestObjectSwiftKotlinSpec::bounceChildBase(const std::shared_ptr<margelo::nitro::image::HybridChildSpec>& child) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridBaseSpec::javaobject>(jni::alias_ref<JHybridChildSpec::javaobject> /* child */)>("bounceChildBase");
    auto __result = method(_javaPart, std::dynamic_pointer_cast<JHybridChildSpec>(child)->getJavaPart());
    return JNISharedPtr::make_shared_from_jni<JHybridBaseSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridChildSpec> JHybridTestObjectSwiftKotlinSpec::castBase(const std::shared_ptr<margelo::nitro::image::HybridBaseSpec>& base) {
    static const auto method = _javaPart->getClass()->getMethod<jni::local_ref<JHybridChildSpec::javaobject>(jni::alias_ref<JHybridBaseSpec::javaobject> /* base */)>("castBase");
    auto __result = method(_javaPart, std::dynamic_pointer_cast<JHybridBaseSpec>(base)->getJavaPart());
    return JNISharedPtr::make_shared_from_jni<JHybridChildSpec>(jni::make_global(__result));
  }

} // namespace margelo::nitro::image
