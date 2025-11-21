//
//  HybridTestView.swift
//  react-native-nitro-test
//
//  Created by Marc Rousavy on 03.10.24.
//

import Foundation
import UIKit

class HybridTestView: HybridTestViewSpec {
    static var counter: Int = 0

    @objc public class func shouldBeRecycled() -> Bool {
        return false
    }

  // UIView
  var view: UIView = UIView()
  var textField: UITextField!
    
  override init() {
      HybridTestView.counter += 1
      view.backgroundColor = .systemRed
      textField = UITextField(frame: CGRect(x: 0, y: 0, width: 100, height: 30))
      textField.borderStyle = .roundedRect
      textField.textAlignment = .center
      textField.text = HybridTestView.counter.description
      view.addSubview(textField)
  }

  // Props
  var isBlue: Bool? = false {
    didSet {
      view.backgroundColor = (isBlue ?? false) ? .systemBlue : .systemRed
        textField.text = HybridTestView.counter.description + "isBlue=" + (isBlue ?? false).description
    }
  }
  var hasBeenCalled: Bool = false
  var colorScheme: ColorScheme = .light
  var someCallback: () -> Void = {}

  // Methods
  func someMethod() throws {
    hasBeenCalled = true
    someCallback()
  }
}
