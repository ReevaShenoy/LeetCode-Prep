class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSub = nums[0]
        currentSum = 0
        
        for x in nums:
            # negative numbers won't contribute to a maximum sum
            if currentSum < 0:
                currentSum = 0
            currentSum += x
            maxSub = max(maxSub, currentSum)
        
        return maxSub