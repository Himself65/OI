struct Solution {}

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut numbers = vec![0; nums1.len() + nums2.len()];
        let mut pos = 0;
        let mut l1 = 0;
        let mut l2 = 0;
        while l1 < nums1.len() && l2 < nums2.len() {
            if nums1[l1] < nums2[l2] {
                numbers[pos] = nums1[l1];
                l1 += 1;
            } else {
                numbers[pos] = nums2[l2];
                l2 += 1;
            }
            pos += 1;
        }
        while l1 < nums1.len() {
            numbers[pos] = nums1[l1];
            l1 += 1;
            pos += 1;
        }
        while l2 < nums2.len() {
            numbers[pos] = nums2[l2];
            l2 += 1;
            pos += 1;
        }
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
