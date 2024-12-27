class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return sum(1 for i in range(len(heights)) if heights[i] != sorted(heights)[i])
