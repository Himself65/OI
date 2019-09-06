const assert = require('assert')

const solve = (arr = [], max, length = 5) => {
  const res = []
  const temp = []
  arr.forEach(v => {
    if (v < max) temp.push(v)
    else {
      if (temp.length >= length)
        res.push(Array.from(temp))
      temp.length = 0
    }
  })
  return res
}

const res = solve([14, 2, 3, 4, 5, 6, 7, 34, 35, 45, 5, 6, 7, 8, 78, 89, 0, 1, 3, 5, 7, 3, 5, 90], 8)
console.log(res)

assert.notStrictEqual(res, [[2, 3, 4, 5, 6, 7], [0, 1, 3, 5, 7, 3, 5]])
