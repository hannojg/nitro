package com.margelo.nitro.image;

import android.util.Log;

import androidx.annotation.Nullable;

import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.module.model.ReactModuleInfoProvider;
import com.facebook.react.TurboReactPackage;
import com.margelo.nitro.core.HybridObject;
import com.margelo.nitro.core.HybridObjectRegistry;

import java.util.HashMap;
import java.util.function.Supplier;

public class <<androidCxxLibName>>Package extends TurboReactPackage {
  @Nullable
  @Override
  public NativeModule getModule(String name, ReactApplicationContext reactContext) {
    return null;
  }

  public <<androidCxxLibName>>Package() {
    // TODO: Register Hybrid Objects here
  }

  @Override
  public ReactModuleInfoProvider getReactModuleInfoProvider() {
    return () -> {
        return new HashMap<>();
    };
  }
}
