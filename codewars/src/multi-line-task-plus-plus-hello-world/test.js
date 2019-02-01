/* global f */
require('./solution')
const resolve = require('path').resolve
const readFileSync = require('fs').readFileSync
const file = readFileSync(resolve(__dirname, 'solution.js'), { encoding: 'utf-8' })

describe('kata: multi-line-task-plus-plus-hello-world', () => {
  describe('Basic tests', () => {
    it('should pass 1', () => {
      /* disable-next-line */
      expect(f()).toEqual('Hello, world!')
    })
  })

  describe('Code length check', () => {
    const content = file.split('\n')
    it('Every line should have less than 3 characters', () => {
      const limit = 3
      content.forEach(t => expect(t.length).toBeLessThan(limit))
    })

    it('There should be less than 40 lines', function () {
      const lineLimit = 40
      expect(content.length).toBeLessThan(lineLimit)
    })
  })
})
