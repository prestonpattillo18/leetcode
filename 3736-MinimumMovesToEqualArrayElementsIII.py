# 1ms (57.44%), 18.96MB (98.46%)

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return (max(nums) * len(nums)) - sum(nums)
