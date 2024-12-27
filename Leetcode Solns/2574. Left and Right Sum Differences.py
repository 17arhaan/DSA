class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        totalSum = sum(nums)
        leftSum = 0
        answer = []

        for i in range(len(nums)):
            rightSum = totalSum - leftSum - nums[i]
            answer.append(abs(leftSum - rightSum))
            leftSum += nums[i]

        return answer
