/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

const listToStr = (list) => {
	let str = ''
	while (list) {
		val = list.val
		list = list.next ? list.next : null
		str += val
	}
	return str.split('').reverse().join('')
}

const strToList = (str) => {
	let arr = str.split('')
	let listNode = new ListNode(arr.shift())
	return arr.reduce((ori, cur) => {
		let ln = new ListNode(cur)
		ln.next = ori
		return ln
	}, listNode)
}

const add = (a, b) => {
	var res = '', c = 0
	a = a.split('')
	b = b.split('')
	while (a.length || b.length || c) {
		c += ~~a.pop() + ~~b.pop()
		res = c % 10 + res
		c = c > 9
	}
	return res
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
const addTwoNumbers = function (l1, l2) {
	let sum = add(listToStr(l1), listToStr(l2))
	return strToList(sum)
}
