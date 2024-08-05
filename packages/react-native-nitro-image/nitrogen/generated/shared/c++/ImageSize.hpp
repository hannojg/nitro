///
/// ImageSize.hpp
/// Tue Aug 06 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif





namespace margelo::nitro::image {

  /**
   * A struct which can be represented as a JavaScript object (ImageSize).
   */
  struct ImageSize {
  public:
    double width;
    double height;

  public:
    explicit ImageSize(double width, double height): width(width), height(height) {}
  };

} // namespace margelo::nitro::image

namespace margelo::nitro {

  using namespace margelo::nitro::image;

  // C++ ImageSize <> JS ImageSize (object)
  template <>
  struct JSIConverter<ImageSize> {
    static inline ImageSize fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return ImageSize(
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "width")),
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "height"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const ImageSize& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "width", JSIConverter<double>::toJSI(runtime, arg.width));
      obj.setProperty(runtime, "height", JSIConverter<double>::toJSI(runtime, arg.height));
      return obj;
    }
  };

} // namespace margelo::nitro
