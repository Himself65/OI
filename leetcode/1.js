/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = function (nums, target) {
	const temp = nums.slice(0)
	nums = nums.sort((a, b) => a - b)
	let l = 0, r = nums.length - 1, mid
	while (nums[l] + nums[r] !== target) {
		const sum = nums[l] + nums[r]
		if (sum > target) {
			r--
		} else {
			l++
		}
	}
	l = temp.indexOf(nums[l])
	r = temp.indexOf(nums[r])
	if (l === r) {
		r = temp.indexOf(temp[l], l + 1)
	}
	if (l > r) {
		return [r, l]
	} else {
		return [l, r]
	}
}
