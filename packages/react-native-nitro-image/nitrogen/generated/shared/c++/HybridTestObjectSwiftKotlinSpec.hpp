///
/// HybridTestObjectSwiftKotlinSpec.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/HybridObject.hpp>)
#include <NitroModules/HybridObject.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

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

#include <string>
#include <optional>
#include <variant>
#include <memory>
#include "HybridTestObjectSwiftKotlinSpec.hpp"
#include <NitroModules/AnyMap.hpp>
#include "Powertrain.hpp"
#include <future>
#include <functional>
#include "Car.hpp"
#include "Person.hpp"
#include <NitroModules/ArrayBuffer.hpp>

namespace margelo::nitro::image {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `TestObjectSwiftKotlin`
   * Inherit this class to create instances of `HybridTestObjectSwiftKotlinSpec` in C++.
   * @example
   * ```cpp
   * class HybridTestObjectSwiftKotlin: public HybridTestObjectSwiftKotlinSpec {
   *   // ...
   * };
   * ```
   */
  class HybridTestObjectSwiftKotlinSpec: public virtual HybridObject {
    public:
      // Constructor
      explicit HybridTestObjectSwiftKotlinSpec(): HybridObject(TAG) { }

      // Destructor
      virtual ~HybridTestObjectSwiftKotlinSpec() { }

    public:
      // Properties
      virtual double getNumberValue() = 0;
      virtual void setNumberValue(double numberValue) = 0;
      virtual bool getBoolValue() = 0;
      virtual void setBoolValue(bool boolValue) = 0;
      virtual std::string getStringValue() = 0;
      virtual void setStringValue(const std::string& stringValue) = 0;
      virtual int64_t getBigintValue() = 0;
      virtual void setBigintValue(int64_t bigintValue) = 0;
      virtual std::optional<std::string> getStringOrUndefined() = 0;
      virtual void setStringOrUndefined(const std::optional<std::string>& stringOrUndefined) = 0;
      virtual std::optional<std::string> getStringOrNull() = 0;
      virtual void setStringOrNull(const std::optional<std::string>& stringOrNull) = 0;
      virtual std::optional<std::string> getOptionalString() = 0;
      virtual void setOptionalString(const std::optional<std::string>& optionalString) = 0;
      virtual std::variant<std::string, double> getSomeVariantFirst() SWIFT_PRIVATE = 0;
      virtual void setSomeVariantFirst(const std::variant<std::string, double>& someVariantFirst) = 0;
      virtual std::shared_ptr<margelo::nitro::image::HybridTestObjectSwiftKotlinSpec> getThisObject() = 0;

    public:
      // Methods
      virtual void simpleFunc() = 0;
      virtual double addNumbers(double a, double b) = 0;
      virtual std::string addStrings(const std::string& a, const std::string& b) = 0;
      virtual void multipleArguments(double num, const std::string& str, bool boo) = 0;
      virtual std::shared_ptr<AnyMap> createMap() = 0;
      virtual std::shared_ptr<AnyMap> mapRoundtrip(const std::shared_ptr<AnyMap>& map) = 0;
      virtual double funcThatThrows() = 0;
      virtual std::string tryOptionalParams(double num, bool boo, const std::optional<std::string>& str) = 0;
      virtual std::string tryMiddleParam(double num, std::optional<bool> boo, const std::string& str) = 0;
      virtual std::optional<Powertrain> tryOptionalEnum(std::optional<Powertrain> value) = 0;
      virtual int64_t calculateFibonacciSync(double value) = 0;
      virtual std::future<int64_t> calculateFibonacciAsync(double value) = 0;
      virtual std::future<void> wait(double seconds) = 0;
      virtual void callCallback(const std::function<void()>& callback) = 0;
      virtual void callAll(const std::function<void()>& first, const std::function<void()>& second, const std::function<void()>& third) = 0;
      virtual void callWithOptional(std::optional<double> value, const std::function<void(std::optional<double> /* maybe */)>& callback) = 0;
      virtual Car getCar() = 0;
      virtual bool isCarElectric(const Car& car) = 0;
      virtual std::optional<Person> getDriver(const Car& car) = 0;
      virtual std::shared_ptr<ArrayBuffer> createArrayBuffer() = 0;
      virtual double getBufferLastItem(const std::shared_ptr<ArrayBuffer>& buffer) = 0;
      virtual void setAllValuesTo(const std::shared_ptr<ArrayBuffer>& buffer, double value) = 0;
      virtual std::shared_ptr<margelo::nitro::image::HybridTestObjectSwiftKotlinSpec> newTestObject() = 0;

    protected:
      // Hybrid Setup
      void loadHybridMethods() override;

    protected:
      // Tag for logging
      static constexpr auto TAG = "TestObjectSwiftKotlin";
  };

} // namespace margelo::nitro::image
