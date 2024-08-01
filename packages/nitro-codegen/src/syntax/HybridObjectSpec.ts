import type { Method } from './Method.js'
import type { Property } from './Property.js'

export interface HybridObjectSpec {
  name: string
  properties: Property[]
  methods: Method[]
}
