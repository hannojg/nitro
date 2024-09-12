///
/// NitroImageOnLoad.swift
/// Thu Sep 12 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

public final class NitroImageOnLoad {
  public static func createImageFactory() -> HybridImageFactorySpecCxx {
    let hybridObject = HybridImageFactory()
    return hybridObject.createCxxBridge()
  }
  
  public static func createSwiftKotlinTestObject() -> HybridSwiftKotlinTestObjectSpecCxx {
    let hybridObject = HybridSwiftKotlinTestObject()
    return hybridObject.createCxxBridge()
  }
}
