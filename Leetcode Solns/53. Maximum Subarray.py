class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s = 0
        maxx = nums[0]
        for i in nums:
            s += i
            maxx = max(s,maxx)
            if s<0:
                s = 0
        return maxx 