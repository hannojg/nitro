///
/// HybridTestObjectSwiftKotlinSpecSwift.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include "HybridTestObjectSwiftKotlinSpec.hpp"

// Forward declaration of `HybridTestObjectSwiftKotlinSpecCxx` to properly resolve imports.
namespace NitroImage { class HybridTestObjectSwiftKotlinSpecCxx; }

// Forward declaration of `HybridTestObjectSwiftKotlinSpec` to properly resolve imports.
namespace margelo::nitro::image { class HybridTestObjectSwiftKotlinSpec; }
// Forward declaration of `HybridTestObjectSwiftKotlinSpecSwift` to properly resolve imports.
namespace margelo::nitro::image { class HybridTestObjectSwiftKotlinSpecSwift; }
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
// Forward declaration of `ArrayBufferHolder` to properly resolve imports.
namespace NitroModules { class ArrayBufferHolder; }

#include <memory>
#include "HybridTestObjectSwiftKotlinSpec.hpp"
#include "HybridTestObjectSwiftKotlinSpecSwift.hpp"
#include <string>
#include <optional>
#include <variant>
#include <NitroModules/AnyMap.hpp>
#include "Powertrain.hpp"
#include <future>
#include <NitroModules/PromiseHolder.hpp>
#include <functional>
#include "Car.hpp"
#include "Person.hpp"
#include <NitroModules/ArrayBuffer.hpp>
#include <NitroModules/ArrayBufferHolder.hpp>

#if __has_include(<NitroModules/HybridContext.hpp>)
#include <NitroModules/HybridContext.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

#include "NitroImage-Swift-Cxx-Umbrella.hpp"

namespace margelo::nitro::image {

  /**
   * The C++ part of HybridTestObjectSwiftKotlinSpecCxx.swift.
   *
   * HybridTestObjectSwiftKotlinSpecSwift (C++) accesses HybridTestObjectSwiftKotlinSpecCxx (Swift), and might
   * contain some additional bridging code for C++ <> Swift interop.
   *
   * Since this obviously introduces an overhead, I hope at some point in
   * the future, HybridTestObjectSwiftKotlinSpecCxx can directly inherit from the C++ class HybridTestObjectSwiftKotlinSpec
   * to simplify the whole structure and memory management.
   */
  class HybridTestObjectSwiftKotlinSpecSwift final: public HybridTestObjectSwiftKotlinSpec {
  public:
    // Constructor from a Swift instance
    explicit HybridTestObjectSwiftKotlinSpecSwift(const NitroImage::HybridTestObjectSwiftKotlinSpecCxx& swiftPart):
      HybridObject(HybridTestObjectSwiftKotlinSpec::TAG),
      _swiftPart(swiftPart) { }

  public:
    // Get the Swift part
    inline NitroImage::HybridTestObjectSwiftKotlinSpecCxx getSwiftPart() noexcept { return _swiftPart; }

  public:
    // Get memory pressure
    inline size_t getExternalMemorySize() noexcept override {
      return _swiftPart.getMemorySize();
    }

  public:
    // Properties
    inline std::shared_ptr<margelo::nitro::image::HybridTestObjectSwiftKotlinSpec> getThisObject() noexcept override {
      auto result = _swiftPart.getThisObject();
      return HybridContext::getOrCreate<HybridTestObjectSwiftKotlinSpecSwift>(result);
    }
    inline double getNumberValue() noexcept override {
      return _swiftPart.getNumberValue();
    }
    inline void setNumberValue(double numberValue) noexcept override {
      _swiftPart.setNumberValue(std::forward<decltype(numberValue)>(numberValue));
    }
    inline bool getBoolValue() noexcept override {
      return _swiftPart.getBoolValue();
    }
    inline void setBoolValue(bool boolValue) noexcept override {
      _swiftPart.setBoolValue(std::forward<decltype(boolValue)>(boolValue));
    }
    inline std::string getStringValue() noexcept override {
      auto result = _swiftPart.getStringValue();
      return result;
    }
    inline void setStringValue(const std::string& stringValue) noexcept override {
      _swiftPart.setStringValue(stringValue);
    }
    inline int64_t getBigintValue() noexcept override {
      return _swiftPart.getBigintValue();
    }
    inline void setBigintValue(int64_t bigintValue) noexcept override {
      _swiftPart.setBigintValue(std::forward<decltype(bigintValue)>(bigintValue));
    }
    inline std::optional<std::string> getStringOrUndefined() noexcept override {
      auto result = _swiftPart.getStringOrUndefined();
      return result;
    }
    inline void setStringOrUndefined(const std::optional<std::string>& stringOrUndefined) noexcept override {
      _swiftPart.setStringOrUndefined(stringOrUndefined);
    }
    inline std::optional<std::string> getStringOrNull() noexcept override {
      auto result = _swiftPart.getStringOrNull();
      return result;
    }
    inline void setStringOrNull(const std::optional<std::string>& stringOrNull) noexcept override {
      _swiftPart.setStringOrNull(stringOrNull);
    }
    inline std::optional<std::string> getOptionalString() noexcept override {
      auto result = _swiftPart.getOptionalString();
      return result;
    }
    inline void setOptionalString(const std::optional<std::string>& optionalString) noexcept override {
      _swiftPart.setOptionalString(optionalString);
    }
    inline std::variant<std::string, double> getSomeVariant() noexcept override {
      auto result = _swiftPart.getSomeVariant();
      return result;
    }
    inline void setSomeVariant(const std::variant<std::string, double>& someVariant) noexcept override {
      _swiftPart.setSomeVariant(someVariant);
    }

  public:
    // Methods
    inline std::shared_ptr<margelo::nitro::image::HybridTestObjectSwiftKotlinSpec> newTestObject() override {
      auto __result = _swiftPart.newTestObject();
      return HybridContext::getOrCreate<HybridTestObjectSwiftKotlinSpecSwift>(__result);
    }
    inline void simpleFunc() override {
      _swiftPart.simpleFunc();
    }
    inline double addNumbers(double a, double b) override {
      auto __result = _swiftPart.addNumbers(std::forward<decltype(a)>(a), std::forward<decltype(b)>(b));
      return __result;
    }
    inline std::string addStrings(const std::string& a, const std::string& b) override {
      auto __result = _swiftPart.addStrings(a, b);
      return __result;
    }
    inline void multipleArguments(double num, const std::string& str, bool boo) override {
      _swiftPart.multipleArguments(std::forward<decltype(num)>(num), str, std::forward<decltype(boo)>(boo));
    }
    inline std::shared_ptr<AnyMap> createMap() override {
      auto __result = _swiftPart.createMap();
      return __result;
    }
    inline std::shared_ptr<AnyMap> mapRoundtrip(const std::shared_ptr<AnyMap>& map) override {
      auto __result = _swiftPart.mapRoundtrip(map);
      return __result;
    }
    inline double funcThatThrows() override {
      auto __result = _swiftPart.funcThatThrows();
      return __result;
    }
    inline std::string tryOptionalParams(double num, bool boo, const std::optional<std::string>& str) override {
      auto __result = _swiftPart.tryOptionalParams(std::forward<decltype(num)>(num), std::forward<decltype(boo)>(boo), str);
      return __result;
    }
    inline std::string tryMiddleParam(double num, std::optional<bool> boo, const std::string& str) override {
      auto __result = _swiftPart.tryMiddleParam(std::forward<decltype(num)>(num), boo, str);
      return __result;
    }
    inline std::optional<Powertrain> tryOptionalEnum(std::optional<Powertrain> value) override {
      auto __result = _swiftPart.tryOptionalEnum(value);
      return __result;
    }
    inline int64_t calculateFibonacciSync(double value) override {
      auto __result = _swiftPart.calculateFibonacciSync(std::forward<decltype(value)>(value));
      return __result;
    }
    inline std::future<int64_t> calculateFibonacciAsync(double value) override {
      auto __result = _swiftPart.calculateFibonacciAsync(std::forward<decltype(value)>(value));
      return __result.getFuture();
    }
    inline std::future<void> wait(double seconds) override {
      auto __result = _swiftPart.wait(std::forward<decltype(seconds)>(seconds));
      return __result.getFuture();
    }
    inline void callCallback(const std::function<void()>& callback) override {
      _swiftPart.callCallback(callback);
    }
    inline void callAll(const std::function<void()>& first, const std::function<void()>& second, const std::function<void()>& third) override {
      _swiftPart.callAll(first, second, third);
    }
    inline void callWithOptional(std::optional<double> value, const std::function<void(std::optional<double> /* maybe */)>& callback) override {
      _swiftPart.callWithOptional(value, callback);
    }
    inline Car getCar() override {
      auto __result = _swiftPart.getCar();
      return __result;
    }
    inline bool isCarElectric(const Car& car) override {
      auto __result = _swiftPart.isCarElectric(car);
      return __result;
    }
    inline std::optional<Person> getDriver(const Car& car) override {
      auto __result = _swiftPart.getDriver(car);
      return __result;
    }
    inline std::shared_ptr<ArrayBuffer> createArrayBuffer() override {
      auto __result = _swiftPart.createArrayBuffer();
      return __result.getArrayBuffer();
    }
    inline double getBufferLastItem(const std::shared_ptr<ArrayBuffer>& buffer) override {
      auto __result = _swiftPart.getBufferLastItem(ArrayBufferHolder(buffer));
      return __result;
    }
    inline void setAllValuesTo(const std::shared_ptr<ArrayBuffer>& buffer, double value) override {
      _swiftPart.setAllValuesTo(ArrayBufferHolder(buffer), std::forward<decltype(value)>(value));
    }

  private:
    NitroImage::HybridTestObjectSwiftKotlinSpecCxx _swiftPart;
  };

} // namespace margelo::nitro::image
