/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 *
 * https://leetcode.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (43.79%)
 * Total Accepted:    67.1K
 * Total Submissions: 153K
 * Testcase Example:  '["Solution", "pickIndex"]\n[[[1]], []]'
 *
 * Given an array w of positive integers, where w[i] describes the weight of
 * index i, write a function pickIndex which randomly picks an index in
 * proportion to its weight.
 *
 * Note:
 *
 *
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output: [null,0]
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output: [null,0,1,1,1,0]
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array w. pickIndex has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 *
 */

int bisect_left(vector<int> &arr, int target) {
  int lo = 0, hi = arr.size() - 1, mid;
  while (lo < hi) {
    mid = lo +  (hi - lo) / 2;
    if (arr[mid] >= target)
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

class Solution {
public:
  vector<int> cv;
  Solution(vector<int> &w) {
    int pre = 0;
    for (auto n : w) cv.push_back(pre += n);
  }

  int pickIndex() { return bisect_left(cv, 1 + (rand() % cv.back())); }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
