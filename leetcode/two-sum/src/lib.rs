struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for p1 in nums.iter().enumerate() {
            for p2 in nums.iter().enumerate() {
                let (pos1, num1) = p1;
                let (pos2, num2) = p2;
                if pos1 == pos2 {
                    continue;
                } else if num1 + num2 == target {
                    return vec![pos1 as i32, pos2 as i32];
                }
            }
        }
        return vec![];
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn test1() {
        let res = Solution::two_sum(vec![2, 7, 11, 15], 9);
        assert_eq!(res, vec![0, 1]);
    }

    #[test]
    fn test2() {
        let res = Solution::two_sum(vec![3, 2, 4], 6);
        assert_eq!(res, vec![1, 2]);
    }

    #[test]
    fn test3() {
        let res = Solution::two_sum(vec![3, 3], 6);
        assert_eq!(res, vec![0, 1]);
    }
}
