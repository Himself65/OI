function permutations (str) {
  if (str.length === 1) {
    return [str]
  }
  let res = []
  let arr = permutations(str.slice(1))
  for (let i = 0; i < arr.length; i++) {
    let partArr = []
    for (let j = 0; j < arr[i].length + 1; j++) {
      let newStr = arr[i].slice(0, j) + str[0] + arr[i].slice(j)
      partArr.push(newStr)
    }
    res = res.concat(partArr)
  }
  const r = []
  new Set(res).forEach(t => r.push(t))
  return r
}

describe('should return correct value', function () {
  it('should pass 1', function () {
    expect(permutations('a')).toEqual(['a'])
  })
  it('should pass 2', function () {
    expect(permutations('ab')).toEqual(['ab', 'ba'])
  })
  it('should pass 3', function () {
    expect(permutations('aabb')).toEqual(['aabb', 'abab', 'abba', 'baab', 'baba', 'bbaa'])
  })
})
