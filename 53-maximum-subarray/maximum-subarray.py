class Solution:
    def maxSubArray(self, nums):
        maxSum = float(-inf)
        currentSum = 0
        for x in nums:
            if(currentSum < 0): currentSum = 0
            currentSum += x
            maxSum = max(maxSum,currentSum)
        return maxSum