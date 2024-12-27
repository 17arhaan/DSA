class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_num = -1
        
        for num in num_set:
            if num > 0 and -num in num_set:
                max_num = max(max_num, num)
        
        return max_num
