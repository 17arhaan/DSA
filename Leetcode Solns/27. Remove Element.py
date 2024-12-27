class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        count = 0
        for num in nums:
            if num != val:
                nums[count] = num
                count += 1
        return count