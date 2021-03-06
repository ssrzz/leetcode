from collections import Counter, defaultdict, OrderedDict, deque
from bisect import bisect_left, bisect_right
from functools import reduce
import string
true = True
false = False
#
# @lc app=leetcode id=1145 lang=python3
#
# [1145] Binary Tree Coloring Game
#
# https://leetcode.com/problems/binary-tree-coloring-game/description/
#
# algorithms
# Medium (49.76%)
# Total Accepted:    10.3K
# Total Submissions: 20.7K
# Testcase Example:  '[1,2,3,4,5,6,7,8,9,10,11]\n11\n3'
#
# Two players play a turn based game on a binary tree.  We are given the root
# of this binary tree, and the number of nodes n in the tree.  n is odd, and
# each node has a distinct value from 1 to n.
#
# Initially, the first player names a value x with 1 <= x <= n, and the second
# player names a value y with 1 <= y <= n and y != x.  The first player colors
# the node with value x red, and the second player colors the node with value y
# blue.
#
# Then, the players take turns starting with the first player.  In each turn,
# that player chooses a node of their color (red if player 1, blue if player 2)
# and colors an uncolored neighbor of the chosen node (either the left child,
# right child, or parent of the chosen node.)
#
# If (and only if) a player cannot choose such a node in this way, they must
# pass their turn.  If both players pass their turn, the game ends, and the
# winner is the player that colored more nodes.
#
# You are the second player.  If it is possible to choose such a y to ensure
# you win the game, return true.  If it is not possible, return false.
#
#
# Example 1:
#
#
# Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
# Output: true
# Explanation: The second player can choose the node with value 2.
#
#
#
# Constraints:
#
#
# root is the root of a binary tree with n nodes and distinct node values from
# 1 to n.
# n is odd.
# 1 <= x <= n <= 100
#
#
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def btreeGameWinningMove(self, r, n, x):
        cter = defaultdict(int)
        self.l = self.r = 0

        def helper(n):
            if not n:
                return 0
            lc, rc = helper(n.left), helper(n.right)
            cter[n.val] += lc + rc + 1
            if n.val == x:
                self.l, self.r = lc, rc
            return cter[n.val]
        helper(r)

        return cter[r.val] > cter[x] * \
            2 or max(self.l, self.r) * 2 > cter[r.val]


sol = Solution()
