# 3ms (80.86%), 20.52MB (23.43%)

from statistics import median

class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        med = statistics.median(nums)

        varMed = 0
        for x in nums:
            varMed += abs(med - x)

        return int(varMed)
