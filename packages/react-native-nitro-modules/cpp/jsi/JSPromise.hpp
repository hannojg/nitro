//
//  JSPromise.hpp
//  react-native-filament
//
//  Created by Marc Rousavy on 11.03.24.
//

#pragma once

#include "OwningReference.hpp"
#include <functional>
#include <jsi/jsi.h>
#include <memory>

namespace margelo::nitro {

using namespace facebook;

/**
 * Represents a JS Promise.
 *
 * `JSPromise` is not thread-safe: It has to be resolved/rejected
 * on the same thread and Runtime as it was created on.
 */
class JSPromise final {
public:
  JSPromise(jsi::Runtime& runtime, jsi::Function&& resolver, jsi::Function&& rejecter);

  /**
   Resolve the Promise with the given `jsi::Value`.
   If the `jsi::Runtime` has already been deleted, this will do nothing.
   */
  void resolve(jsi::Runtime& runtime, jsi::Value&& result);
  /**
   Resolve the Promise with the given error message.
   If the `jsi::Runtime` has already been deleted, this will do nothing.
   */
  void reject(jsi::Runtime& runtime, std::string error);

private:
  OwningReference<jsi::Function> _resolver;
  OwningReference<jsi::Function> _rejecter;
  static constexpr auto TAG = "Promise";

public:
  using RunPromise = std::function<void(jsi::Runtime& runtime, std::shared_ptr<JSPromise> promise)>;
  /**
   * Create a new Promise using the JS `Promise` constructor and runs the given `run` function.
   * The resulting Promise should be returned to JS so it can be awaited.
   */
  static jsi::Value createPromise(jsi::Runtime& runtime, RunPromise&& run);
};

} // namespace margelo::nitro
