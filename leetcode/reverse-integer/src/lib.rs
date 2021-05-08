struct Solution {}

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        return reverse_iter(0, x);

        fn reverse_iter(v: i32, x: i32) -> i32 {
            if x == 0 {
                return v;
            }
            let pop = x % 10;
            return match v.checked_mul(10) {
                None => reverse_iter(0, 0),
                Some(v) => match v.checked_add(pop) {
                    None => reverse_iter(0, 0),
                    Some(v) => reverse_iter(v, x / 10)
                }
            };
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn it_works() {
        assert_eq!(Solution::reverse(123), 321);
        assert_eq!(Solution::reverse(-123), -321);
        assert_eq!(Solution::reverse(0), 0);
        assert_eq!(Solution::reverse(1534236469), 0);
    }
}
