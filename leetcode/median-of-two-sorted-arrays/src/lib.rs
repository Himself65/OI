struct Solution {}

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut numbers: Vec<i32> = [&nums1[..], &nums2[..]].concat();
        numbers.sort();
        let length = numbers.len();
        return if length % 2 == 1 {
            numbers[length / 2] as f64
        } else {
            let right = numbers[length / 2];
            let left = numbers[length / 2 - 1];
            // tag: type in rust
            (right as f64 + left as f64) / 2.0
        };
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn it_works() {
        assert_eq!(Solution::find_median_sorted_arrays(vec![1, 2], vec![3, 4]), 2.5);
    }
}
