/*
 * @lc app=leetcode id=402 lang=rust
 *
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (27.66%)
 * Total Accepted:    90.9K
 * Total Submissions: 328.5K
 * Testcase Example:  '"1432219"\n3'
 *
 * Given a non-negative integer num represented as a string, remove k digits
 * from the number so that the new number is the smallest possible.
 *
 *
 * Note:
 *
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 *
 *
 *
 *
 * Example 1:
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 *
 *
 *
 * Example 2:
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 *
 *
 *
 * Example 3:
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 *
 *
 */
impl Solution {
    pub fn remove_kdigits(num: String, k: i32) -> String {
        let (mut k, mut res) = (k as usize, "".to_string());

        for n in num.chars() {
            while k > 0 && !res.is_empty() && n < res.chars().last().unwrap() {
                k -= 1;
                res.pop();
            }
            if !res.is_empty() || n != '0' { res.push(n); }
        }

        while !res.is_empty() && k > 0 { res.pop(); k -= 1;}

        if !res.is_empty() { res } else { "0".to_string() }
    }
}

// pub struct Solution;
use std::cmp::max;
use std::cmp::min;
use std::collections::HashMap;
use std::collections::HashSet;
use std::fmt::Debug;
use std::hash::Hash;
use std::iter::FromIterator;
// use std::collections::VecDeque;
// use std::collections::BTreeMap;
use std::any::type_name;
use std::collections::BinaryHeap;

pub fn char2usize(c: char) -> usize {
    c as usize - 97
}

pub struct Helper;
impl Helper {
    pub fn stringify(str_vector: Vec<&str>) -> Vec<String> {
        // Convert a vector of &str to vector or String for coding convenience
        str_vector
            .iter()
            .map(|c| c.to_string())
            .collect::<Vec<String>>()
    }
}

// To get the type of a variable
pub fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}

#[allow(dead_code)]
pub fn print_map<K: Debug + Eq + Hash, V: Debug>(map: &HashMap<K, V>) {
    for (k, v) in map.iter() {
        println!("{:?}: {:?}", k, v);
    }
}

#[allow(dead_code)]
pub fn say_vec(nums: Vec<i32>) {
    println!("{:?}", nums);
}

#[allow(dead_code)]
pub fn char_frequency(s: String) -> HashMap<char, i32> {
    let mut res: HashMap<char, i32> = HashMap::new();
    for c in s.chars() {
        *res.entry(c).or_insert(0) += 1;
    }
    res
}

#[allow(dead_code)]
pub fn string_counter(s: String) -> HashMap<char, i32> {
    let mut res = HashMap::new();
    for c in s.chars() {
        *res.entry(c).or_insert(0) += 1;
    }
    res
}

#[allow(dead_code)]
pub fn vec_counter(arr: Vec<i32>) -> HashMap<i32, i32> {
    let mut c = HashMap::new();
    for n in arr {
        *c.entry(n).or_insert(0) += 1;
    }
    c
}

#[allow(dead_code)]
pub fn vec_to_hashset(arr: Vec<i32>) -> HashSet<i32> {
    HashSet::from_iter(arr.iter().cloned())
}

#[allow(dead_code)]
pub fn int_to_char(n: i32) -> char {
    // Convert number 0 to a, 1 to b, ...
    assert!(n >= 0 && n <= 25);
    (n as u8 + 'a' as u8) as char
}

#[allow(dead_code)]
fn sayi32(i: i32) {
    println!("{}", i);
}

#[allow(dead_code)]
fn sayi32_arr(arr: &Vec<i32>) {
    println!("{:?}", arr);
}

#[allow(dead_code)]
pub fn bisect_left(arr: &Vec<i32>, target: i32) -> usize {
    if target > *arr.last().unwrap() {
        return arr.len();
    }
    let (mut lo, mut hi) = (0, arr.len() - 1);
    let mut mid;
    while lo < hi {
        mid = (lo + hi) >> 1;
        if arr[mid as usize] >= target {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    lo
}

#[allow(dead_code)]
pub fn bisect_right(arr: &Vec<i32>, target: i32) -> usize {
    let (mut lo, mut hi) = (0, arr.len() - 1);
    let mut mid;
    while lo < hi {
        mid = (lo + hi + 1) >> 1;
        if arr[mid as usize] > target {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    if arr[hi] > target {
        hi
    } else {
        hi + 1
    }
}

pub struct FenwickTree {
    vals: Vec<i32>,
}

impl FenwickTree {
    pub fn new(size: usize) -> FenwickTree {
        FenwickTree {
            vals: Vec::from_iter(std::iter::repeat(0).take(size + 1)),
        }
    }

    pub fn update(&mut self, mut i: usize, val: i32) {
        let size = self.vals.len();
        while i < size {
            self.vals[i] += val;
            i += i & (!i + 1);
        }
    }

    pub fn get(&mut self, mut i: usize) -> i32 {
        let mut res = 0;
        while i > 0 {
            res += self.vals[i];
            i -= i & (!i + 1);
        }
        res
    }
}

#[allow(dead_code)]
fn get_vector_sum(a: &Vec<i32>) -> i32 {
    a.iter().fold(0, |mut sum, &x| {
        sum += x;
        sum
    })
}

#[allow(dead_code)]
fn get_vector_product(a: &Vec<i32>) -> i32 {
    a.iter().fold(1, |mut prod, &x| {
        prod *= x;
        prod
    })
}

// There is NO gcd in standard lib for Rust, surprise.
#[allow(dead_code)]
fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}