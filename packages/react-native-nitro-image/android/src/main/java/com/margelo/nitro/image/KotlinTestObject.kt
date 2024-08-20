package com.margelo.nitro.image

import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.core.ArrayBuffer
import com.margelo.nitro.functions.Function1
import java.nio.ByteBuffer

class KotlinTestObject: HybridKotlinTestObjectSpec() {
    override var numberValue: Double = 0.0
    override var optionalNumber: Double? = null
    override var primitiveArray: DoubleArray = doubleArrayOf()
    override var carCollection: Array<Car> = emptyArray()
    override var someBuffer: ArrayBuffer

    override val memorySize: Long
        get() = 0

    init {
        someBuffer = ArrayBuffer(ByteBuffer.allocateDirect(1024 * 1024))
    }

    // Methods
    @DoNotStrip
    fun getCallable(): com.margelo.nitro.functions.Function1<Int, Double> {
        return Function1 { (it * 2).toInt() }
    }
}