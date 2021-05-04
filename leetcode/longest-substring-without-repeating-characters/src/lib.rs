struct Solution {}

// start
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        use std::collections::HashSet;

        let s = s.as_bytes();
        let mut l = 0;
        let mut r = 0;
        let mut res = 0;
        let mut set: HashSet<u8> = HashSet::with_capacity(26);
        while r < s.len() {
            if set.contains(&s[r]) {
                set.remove(&s[l]);
                l += 1;
            } else {
                res = i32::max(res, (r - l + 1) as i32);
                set.insert(s[r]);
                r += 1;
            }
        }
        return res;
    }
}
// end

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn it_works() {
        assert_eq!(Solution::length_of_longest_substring(String::from("abcabcbcc")), 3);
        assert_eq!(Solution::length_of_longest_substring(String::from("abcdabcd")), 4);
        assert_eq!(Solution::length_of_longest_substring(String::from("aaa")), 1);
        assert_eq!(Solution::length_of_longest_substring(String::from("cccdddd")), 2);
        assert_eq!(Solution::length_of_longest_substring(String::from("a")), 1);
        assert_eq!(Solution::length_of_longest_substring(String::from("pwwkew")), 3);
    }
}
