import { type HybridObject, type AnyMap } from 'react-native-nitro-modules'

type Float3 = [number, number, number]
type TestTuple = [number, string, boolean]

type Powertrain = 'electric' | 'gas' | 'hybrid'

interface Car {
  year: number
  make: string
  model: string
  power: number
  powertrain: Powertrain
  driver?: Person
}

interface Person {
  name: string
  age: number
}

export interface TestObject extends HybridObject<{ ios: 'c++' }> {
  // Test Primitives
  numberValue: number
  boolValue: boolean
  stringValue: string
  bigintValue: bigint
  stringOrUndefined: string | undefined
  stringOrNull: string | null
  optionalString?: string

  // Basic function tests
  simpleFunc(): void
  multipleArguments(num: number, str: string, boo: boolean): void

  // Maps
  createMap(): AnyMap
  mapRoundtrip(map: AnyMap): AnyMap

  // Errors
  valueThatWillThrowOnAccess: number
  funcThatThrows(): number

  // Optional parameters
  tryOptionalParams(num: number, boo: boolean, str?: string): string
  tryMiddleParam(num: number, boo: boolean | undefined, str: string): string

  // Variants
  someVariant: number | string
  passVariant(
    either: number | string | number[] | string[] | boolean
  ): number | string

  // Tuples
  someTuple: [number, string]
  flip(tuple: Float3): Float3
  passTuple(tuple: TestTuple): [number, string, boolean]

  // Promises
  calculateFibonacciSync(value: number): bigint
  calculateFibonacciAsync(value: number): Promise<bigint>
  wait(seconds: number): Promise<void>

  // Callbacks
  callCallback(callback: () => void): void
  getValueFromJSCallback(getValue: () => number): void
  getValueFromJSCallbackAndWait(getValue: () => number): Promise<number>
  callAll(first: () => void, second: () => void, third: () => void): void
  getValueFromJsCallback(
    callback: () => string,
    andThenCall: (valueFromJs: string) => void
  ): Promise<void>

  // Objects
  getCar(): Car
  isCarElectric(car: Car): boolean
  getDriver(car: Car): Person | undefined

  // ArrayBuffers
  createArrayBuffer(): ArrayBuffer
  getBufferLastItem(buffer: ArrayBuffer): number
  setAllValuesTo(buffer: ArrayBuffer, value: number): void

  // Other HybridObjects
  readonly self: TestObject
  newTestObject(): TestObject
}
