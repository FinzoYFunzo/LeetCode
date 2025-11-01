// Last Submission
// 0ms | Beats 100%

struct Solution;

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let s = x.to_string();
        s.chars().eq(s.chars().rev())
    }
}

fn main() {
    println!("{}", Solution::is_palindrome(121)); // true
    println!("{}", Solution::is_palindrome(-121)); // false
    println!("{}", Solution::is_palindrome(10)); // false
}
