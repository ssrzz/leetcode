#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
/**
Given the coordinates of four points in 2D space, return whether the four points
could construct a square.
The coordinate (x,y) of a point is represented by an integer array with two
integers.
Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
 Note:
All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles
(90-degree angles).
Input points have no order.

 **/
using namespace std;

static int speed_up = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    unordered_set<int> s({distance(p1, p2), distance(p1, p3), distance(p1, p4),
                          distance(p2, p3), distance(p2, p4),
                          distance(p3, p4)});
    return s.size() == 2 && !s.count(0);
  }

  int distance(std::vector<int> &pa, std::vector<int> &pb) {
    return (pa[0] - pb[0]) * (pa[0] - pb[0]) +
           (pa[1] - pb[1]) * (pa[1] - pb[1]);
  }
};

int main() { Solution s; }
