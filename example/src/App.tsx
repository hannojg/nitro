import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
import { ImageConstructors, HybridTestObject } from 'react-native-nitro-image'

export default function App() {
  const image = React.useMemo(() => {
    console.log('Loading image...')
    const i = ImageConstructors.loadImageFromSystemName('heart.fill')
    ImageConstructors.bounceBack(i)
    ImageConstructors.bounceBack(i)
    ImageConstructors.bounceBack(i)
    console.log('Image loaded!')
    console.log(`Image is ${i.size.width}x${i.size.height}`)
    return i
  }, [])

  React.useEffect(() => {
    image.saveToFile('some path', (path) => {
      console.log('saved to ' + path + '!')
    })
  }, [])
  console.log('before')
  const res = HybridTestObject.passVariant(5)
  console.log(`variant result: ${res} (${typeof res})`)

  const map = HybridTestObject.createMap()
  console.log(`map result:`, map)

  const flipped = HybridTestObject.flip([10, 5, 0])
  console.log(`[10, 5, 0] -> [${flipped.join(', ')}]`)

  const test = HybridTestObject.passTuple([53, 'helo', false])
  console.log('tuple result:', test)

  const optionalResult = HybridTestObject.tryOptionalParams(55, true)
  console.log('optional result:', optionalResult)

  try {
    HybridTestObject.funcThatThrows()
    console.error(`Function should've thrown by now!`)
  } catch (e) {
    console.log("Throw worked!", e)
  }
  try {
    HybridTestObject.valueThatWillThrowOnAccess
    console.error(`Value should've thrown by now!`)
  } catch (e) {
    console.log("Throw worked!", e)
  }
  try {
    HybridTestObject.valueThatWillThrowOnAccess = 55
    console.error(`Value should've thrown by now!`)
  } catch (e) {
    console.log("Throw worked!", e)
  }

  React.useEffect(() => {
    const run = async () => {
      console.log('Passing "Hi from JS!" to C++...')
      try {
        await HybridTestObject.getValueFromJsCallback(() => "Hi from JS!", (nativestring) => {
          console.log(`Received callback from C++: "${nativestring}"`)
        })
        console.log('JS callback test completed!')
      } catch (e) {
        console.error(`Failed to pass string from JS -> C++ -> JS:`, e)
      }

    }
    run()
  }, [])

  return (
    <View style={styles.container}>
      <Text>Image is {image.size.width.toFixed(0)}x{image.size.height.toFixed(0)}!</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
