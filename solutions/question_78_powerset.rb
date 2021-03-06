
# Given a set of distinct integers, nums, return all possible subsets (the power set).
#
# Note: The solution set must not contain duplicate subsets.
#
# For example,
# If nums = [1,2,3], a solution is:
#
# [
#   [3],
#   [1],
#   [2],
#   [1,2,3],
#   [1,3],
#   [2,3],
#   [1,2],
#   []
# ]

# @param {Integer[]} nums
# @return {Integer[][]}
def subsets(nums)
  r = []
  (nums.size + 1).times { |i| r += nums.combination(i).to_a }
  r
end

nums = [1, 2]
p subsets(nums)
