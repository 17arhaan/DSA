class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for element in nums:
            if element in seen:
                return True
            seen.add(element)
        return False
    

    # return (len(nums) != len(set(nums)))