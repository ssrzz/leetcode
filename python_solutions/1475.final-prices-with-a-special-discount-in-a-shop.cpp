/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 *
 * https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
 *
 * algorithms
 * Easy (77.09%)
 * Total Accepted:    5K
 * Total Submissions: 6.5K
 * Testcase Example:  '[8,4,6,2,3]'
 *
 * Given the array prices where prices[i] is the price of the ith item in a
 * shop. There is a special discount for items in the shop, if you buy the ith
 * item, then you will receive a discount equivalent to prices[j] where j is
 * the minimum index such that j > i and prices[j] <= prices[i], otherwise, you
 * will not receive any discount at all.
 *
 * Return an array where the ith element is the final price you will pay for
 * the ith item of the shop considering the special discount.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [8,4,6,2,3]
 * Output: [4,2,4,2,3]
 * Explanation: 
 * For item 0 with price[0]=8 you will receive a discount equivalent to
 * prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4. 
 * For item 1 with price[1]=4 you will receive a discount equivalent to
 * prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2. 
 * For item 2 with price[2]=6 you will receive a discount equivalent to
 * prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4. 
 * For items 3 and 4 you will not receive any discount at all.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [1,2,3,4,5]
 * Output: [1,2,3,4,5]
 * Explanation: In this case, for all items, you will not receive any discount
 * at all.
 *
 *
 * Example 3:
 *
 *
 * Input: prices = [10,1,1,6]
 * Output: [9,0,1,6]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 500
 * 1 <= prices[i] <= 10^3
 *
 *
 */
class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    stack<int> s;
    for (int i = 0; i < prices.size(); i++) {
      while (!s.empty() and prices[s.top()] >= prices[i]) {
        prices[s.top()] -= prices[i];
        s.pop();
      }
      s.push(i);
    }
    return prices;
  }
};

static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();