//
// Created by Marc Rousavy on 21.02.24.
//

#pragma once

#include "CountTrailingOptionals.hpp"
#include "HybridContext.hpp"
#include "JSIConverter.hpp"
#include "NitroLogger.hpp"
#include "OwningReference.hpp"
#include <functional>
#include <jsi/jsi.h>
#include <memory>
#include <mutex>
#include <type_traits>
#include <unordered_map>

namespace margelo::nitro {

enum class MethodType { METHOD, GETTER, SETTER };

using namespace facebook;

/**
 * Represents a C++ object that is exposed to JS.
 * `HybridObject`s can have native getters and setters, and normal methods.
 *
 * To implement a `HybridObject`, simply inherit from this class and override `loadHybridMethods`
 * to register the given getters, setters or methods.
 *
 * The new class can then be passed to JS using the `JSIConverter<HybridObject>`.
 */
class HybridObject : public jsi::HostObject, public std::enable_shared_from_this<HybridObject> {
public:
  struct HybridFunction {
    jsi::HostFunctionType function;
    size_t parameterCount;
  };

public:
  /**
   * Create a new instance of a `HybridObject`.
   * The given `name` will be used for logging and stringifying.
   */
  explicit HybridObject(const char* name);
  /**
   * Called when no more references to the given `HybridObject` exist in both C++ and JS.
   * JS might keep references for longer, as it is a garbage collected language.
   */
  virtual ~HybridObject();
  /**
   * HybridObjects cannot be copied.
   */
  HybridObject(const HybridObject& copy) = delete;
  /**
   * HybridObjects cannot be moved.
   */
  HybridObject(HybridObject&& move) = delete;

public:
  void set(jsi::Runtime&, const jsi::PropNameID& name, const jsi::Value& value) override;
  jsi::Value get(jsi::Runtime& runtime, const jsi::PropNameID& propName) override;
  std::vector<jsi::PropNameID> getPropertyNames(jsi::Runtime& runtime) override;

public:
  /**
   * Get the `std::shared_ptr` instance of this HybridObject.
   * The HybridObject must be managed inside a `shared_ptr` already, otherwise this will fail.
   */
  template <typename Derived>
  std::shared_ptr<Derived> shared() {
    return std::static_pointer_cast<Derived>(shared_from_this());
  }

public:
  /**
   * Get the total size of any external (heap) allocations this `HybridObject` (or
   * a subclass of it) has made.
   * This includes any base allocations (such as function cache), as well as
   * overridden extra memory size.
   */
  size_t getTotalExternalMemorySize() noexcept;

  /**
   * Return the `jsi::Object` that holds this `HybridObject` (boxed in a `jsi::Value`)
   * Compared to other `jsi::HostObject`s, the `HybridObject` actually
   * caches the created `jsi::Object` instances for safer memory management.
   */
  jsi::Value toObject(jsi::Runtime& runtime);

public:
  /**
   * Get the HybridObject's name
   */
  std::string getName();
  /**
   * Get a string representation of this HostObject, useful for logging or debugging.
   */
  virtual std::string toString();
  /**
   * Compare this HybridObject for reference equality to the other HybridObject.
   *
   * While two `jsi::Object`s of the same `HybridObject` might not be equal when compared with `==`,
   * they might still be the same `HybridObject` - in this case `equals(other)` will return true.
   */
  bool equals(std::shared_ptr<HybridObject> other);

protected:
  /**
   * Get the size of any external (heap) allocations this `HybridObject` has made, in bytes.
   * This will be used to notify the JS GC about memory pressure.
   */
  virtual inline size_t getExternalMemorySize() noexcept {
    return 0;
  }

protected:
  /**
   * Loads all native methods of this `HybridObject` to be exposed to JavaScript.
   * The base implementation registers a `toString()` method and `name` property.
   *
   * Example:
   *
   * ```cpp
   * int User::getAge() {
   *   return 23;
   * }
   *
   * void User::loadHybridMethods() {
   *   HybridObject::loadHybridMethods();
   *   registerHybridMethod("getAge", &User::getAge, this);
   * }
   * ```
   */
  virtual void loadHybridMethods();

private:
  static constexpr auto TAG = "HybridObject";
  const char* _name = TAG;
  int _instanceId = 1;
  bool _didLoadMethods = false;
  std::unique_ptr<std::mutex> _mutex;
  std::unordered_map<std::string, HybridFunction> _methods;
  std::unordered_map<std::string, jsi::HostFunctionType> _getters;
  std::unordered_map<std::string, jsi::HostFunctionType> _setters;
  std::unordered_map<jsi::Runtime*, std::unordered_map<std::string, OwningReference<jsi::Function>>> _functionCache;
  std::unordered_map<jsi::Runtime*, BorrowingReference<jsi::Object>> _jsObjects;

private:
  inline void ensureInitialized(jsi::Runtime& runtime);

private:
  template <typename Derived, typename ReturnType, typename... Args, size_t... Is>
  static inline jsi::Value callMethod(Derived* obj, ReturnType (Derived::*method)(Args...), jsi::Runtime& runtime, const jsi::Value* args,
                                      size_t argsSize, std::index_sequence<Is...>) {
    jsi::Value defaultValue;

    if constexpr (std::is_void_v<ReturnType>) {
      // It's a void method.
      (obj->*method)(JSIConverter<std::decay_t<Args>>::fromJSI(runtime, Is < argsSize ? args[Is] : defaultValue)...);
      return jsi::Value::undefined();
    } else {
      // It's returning some C++ type, we need to convert that to a JSI value now.
      ReturnType result = (obj->*method)(JSIConverter<std::decay_t<Args>>::fromJSI(runtime, Is < argsSize ? args[Is] : defaultValue)...);
      return JSIConverter<std::decay_t<ReturnType>>::toJSI(runtime, std::move(result));
    }
  }

  template <typename Derived, typename ReturnType, typename... Args>
  static inline jsi::HostFunctionType createHybridMethod(std::string name, ReturnType (Derived::*method)(Args...), Derived* derivedInstance,
                                                         MethodType type) {
    return [name, derivedInstance, method, type](jsi::Runtime& runtime, const jsi::Value& thisVal, const jsi::Value* args,
                                                 size_t count) -> jsi::Value {
      constexpr size_t optionalArgsCount = trailing_optionals_count_v<Args...>;
      constexpr size_t maxArgsCount = sizeof...(Args);
      constexpr size_t minArgsCount = maxArgsCount - optionalArgsCount;
      bool isWithinArgsRange = (count >= minArgsCount && count <= maxArgsCount);
      if (!isWithinArgsRange) {
        // invalid amount of arguments passed!
        std::string hybridObjectName = derivedInstance->_name;
        if (minArgsCount == maxArgsCount) {
          // min and max args length is the same, so we don't have any optional parameters. fixed count
          throw jsi::JSError(runtime, hybridObjectName + "." + name + "(...) expected " + std::to_string(maxArgsCount) +
                                          " arguments, but received " + std::to_string(count) + "!");
        } else {
          // min and max args length are different, so we have optional parameters - variable length arguments.
          throw jsi::JSError(runtime, hybridObjectName + "." + name + "(...) expected between " + std::to_string(minArgsCount) + " and " +
                                          std::to_string(maxArgsCount) + " arguments, but received " + std::to_string(count) + "!");
        }
      }

      try {
        if constexpr (std::is_same_v<ReturnType, jsi::Value>) {
          // If the return type is a jsi::Value, we assume the user wants full JSI code control.
          // The signature must be identical to jsi::HostFunction (jsi::Runtime&, jsi::Value& this, ...)
          return (derivedInstance->*method)(runtime, thisVal, args, count);
        } else {
          // Call the actual method with JSI values as arguments and return a JSI value again.
          // Internally, this method converts the JSI values to C++ values.
          return callMethod(derivedInstance, method, runtime, args, count, std::index_sequence_for<Args...>{});
        }
      } catch (const std::exception& exception) {
        std::string hybridObjectName = derivedInstance->_name;
        std::string message = exception.what();
        std::string suffix = type == MethodType::METHOD ? "(...)" : "";
        throw jsi::JSError(runtime, hybridObjectName + "." + name + suffix + ": " + message);
      } catch (...) {
        std::string hybridObjectName = derivedInstance->_name;
        std::string errorName = TypeInfo::getCurrentExceptionName();
        std::string suffix = type == MethodType::METHOD ? "(...)" : "";
        throw jsi::JSError(runtime, hybridObjectName + "." + name + suffix + " threw an unknown " + errorName + " error.");
      }
    };
  }

protected:
  template <typename Derived, typename ReturnType, typename... Args>
  inline void registerHybridMethod(std::string name, ReturnType (Derived::*method)(Args...), Derived* derivedInstance) {
    if (_getters.contains(name) || _setters.contains(name)) [[unlikely]] {
      throw std::runtime_error("Cannot add Hybrid Method \"" + name + "\" - a property with that name already exists!");
    }
    if (_methods.contains(name)) [[unlikely]] {
      throw std::runtime_error("Cannot add Hybrid Method \"" + name + "\" - a method with that name already exists!");
    }

    _methods[name] = HybridFunction{.function = createHybridMethod(name, method, derivedInstance, MethodType::METHOD),
                                    .parameterCount = sizeof...(Args)};
  }

  template <typename Derived, typename ReturnType>
  inline void registerHybridGetter(std::string name, ReturnType (Derived::*method)(), Derived* derivedInstance) {
    if (_getters.contains(name)) [[unlikely]] {
      throw std::runtime_error("Cannot add Hybrid Property Getter \"" + name + "\" - a getter with that name already exists!");
    }
    if (_methods.contains(name)) [[unlikely]] {
      throw std::runtime_error("Cannot add Hybrid Property Getter \"" + name + "\" - a method with that name already exists!");
    }

    _getters[name] = createHybridMethod(name, method, derivedInstance, MethodType::GETTER);
  }

  template <typename Derived, typename ValueType>
  inline void registerHybridSetter(std::string name, void (Derived::*method)(ValueType), Derived* derivedInstance) {
    if (_setters.contains(name)) [[unlikely]] {
      throw std::runtime_error("Cannot add Hybrid Property Setter \"" + name + "\" - a setter with that name already exists!");
    }
    if (_methods.contains(name)) [[unlikely]] {
      throw std::runtime_error("Cannot add Hybrid Property Setter \"" + name + "\" - a method with that name already exists!");
    }

    _setters[name] = createHybridMethod(name, method, derivedInstance, MethodType::SETTER);
  }
};

} // namespace margelo::nitro
