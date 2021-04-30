#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val,
        }
    }
}

struct Solution {}

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        return generate_list_node(l1, l2, 0);

        fn generate_list_node(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, carry: i32) -> Option<Box<ListNode>> {
            match (l1, l2, carry) {
                (None, None, 0) => None,
                (None, None, c) => Some(Box::new(ListNode::new(c))),
                (Some(l), None, _) | (None, Some(l), _) => {
                    let sum = l.val + carry;
                    Some(Box::new(ListNode { val: sum % 10, next: generate_list_node(l.next, None, sum / 10) }))
                }
                (Some(l1), Some(l2), _) => {
                    let sum = l1.val + l2.val + carry;
                    Some(Box::new(ListNode { val: sum % 10, next: generate_list_node(l1.next, l2.next, sum / 10) }))
                }
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let l1 = Some(Box::new(ListNode {
            val: 2,
            next: Some(Box::new(ListNode {
                val: 4,
                next: Some(Box::new(ListNode {
                    val: 3,
                    next: None,
                })),
            })),
        }));
        let l2 = Some(Box::new(ListNode {
            val: 5,
            next: Some(Box::new(ListNode {
                val: 6,
                next: Some(Box::new(ListNode {
                    val: 4,
                    next: None,
                })),
            })),
        }));
        assert_eq!(Solution::add_two_numbers(l1, l2), Some(Box::new(ListNode {
            val: 7,
            next: Some(Box::new(ListNode {
                val: 0,
                next: Some(Box::new(ListNode {
                    val: 8,
                    next: None,
                })),
            })),
        })));
    }
}
