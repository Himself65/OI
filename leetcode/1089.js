/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
const duplicateZeros = arr => {
	for (let i = 0; i < arr.length - 1; ++i) {
		if (arr[i] === 0) {
			let val = arr[i + 1], temp = arr[i + 2]
			arr[i + 1] = 0
			for (let j = i + 2; j < arr.length; ++j) {
				arr[j] = val
				val = temp
				temp = arr[j + 1]
			}
			++i
		}
	}
}
