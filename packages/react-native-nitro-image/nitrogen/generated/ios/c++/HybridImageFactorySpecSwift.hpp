///
/// HybridImageFactorySpecSwift.hpp
/// Mon Aug 12 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include "NitroImage-Swift-Cxx-Umbrella.hpp"

#include "HybridImageFactorySpec.hpp"

// Forward declaration of `HybridImageFactorySpecCxx` to properly resolve imports.
namespace NitroImage { class HybridImageFactorySpecCxx; }

// Forward declaration of `HybridImageSpec` to properly resolve imports.
namespace margelo::nitro::image { class HybridImageSpec; }
// Forward declaration of `HybridImageSpecSwift` to properly resolve imports.
namespace margelo::nitro::image { class HybridImageSpecSwift; }

#include "HybridImageSpec.hpp"
#include "HybridImageSpecSwift.hpp"

#if __has_include(<NitroModules/HybridContext.hpp>)
#include <NitroModules/HybridContext.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

namespace margelo::nitro::image {

  /**
   * The C++ part of HybridImageFactorySpecCxx.swift.
   *
   * HybridImageFactorySpecSwift (C++) accesses HybridImageFactorySpecCxx (Swift), and might
   * contain some additional bridging code for C++ <> Swift interop.
   *
   * Since this obviously introduces an overhead, I hope at some point in
   * the future, HybridImageFactorySpecCxx can directly inherit from the C++ class HybridImageFactorySpec
   * to simplify the whole structure and memory management.
   */
  class HybridImageFactorySpecSwift final: public HybridImageFactorySpec {
  public:
    // Constructor from a Swift instance
    explicit HybridImageFactorySpecSwift(const NitroImage::HybridImageFactorySpecCxx& swiftPart): HybridImageFactorySpec(), _swiftPart(swiftPart) { }

  public:
    // Get the Swift part
    inline NitroImage::HybridImageFactorySpecCxx getSwiftPart() noexcept { return _swiftPart; }

  public:
    // Get memory pressure
    inline size_t getExternalMemorySize() noexcept override {
      return _swiftPart.getMemorySize();
    }

  public:
    // Properties
    

  public:
    // Methods
    inline std::shared_ptr<margelo::nitro::image::HybridImageSpec> loadImageFromFile(const std::string& path) override {
    auto valueOrError = _swiftPart.loadImageFromFile(std::forward<decltype(path)>(path));
    if (valueOrError.isError()) [[unlikely]] {
      throw std::runtime_error(valueOrError.getError());
    }
    auto value = valueOrError.getValue();
    return HybridContext::getOrCreate<HybridImageSpecSwift>(value);
  }
  inline std::shared_ptr<margelo::nitro::image::HybridImageSpec> loadImageFromURL(const std::string& path) override {
    auto valueOrError = _swiftPart.loadImageFromURL(std::forward<decltype(path)>(path));
    if (valueOrError.isError()) [[unlikely]] {
      throw std::runtime_error(valueOrError.getError());
    }
    auto value = valueOrError.getValue();
    return HybridContext::getOrCreate<HybridImageSpecSwift>(value);
  }
  inline std::shared_ptr<margelo::nitro::image::HybridImageSpec> loadImageFromSystemName(const std::string& path) override {
    auto valueOrError = _swiftPart.loadImageFromSystemName(std::forward<decltype(path)>(path));
    if (valueOrError.isError()) [[unlikely]] {
      throw std::runtime_error(valueOrError.getError());
    }
    auto value = valueOrError.getValue();
    return HybridContext::getOrCreate<HybridImageSpecSwift>(value);
  }
  inline std::shared_ptr<margelo::nitro::image::HybridImageSpec> bounceBack(const std::shared_ptr<margelo::nitro::image::HybridImageSpec>& image) override {
    auto valueOrError = _swiftPart.bounceBack(std::static_pointer_cast<HybridImageSpecSwift>(image)->getSwiftPart());
    if (valueOrError.isError()) [[unlikely]] {
      throw std::runtime_error(valueOrError.getError());
    }
    auto value = valueOrError.getValue();
    return HybridContext::getOrCreate<HybridImageSpecSwift>(value);
  }

  private:
    NitroImage::HybridImageFactorySpecCxx _swiftPart;
  };

} // namespace margelo::nitro::image
