class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        left = 0
        minLen = float(inf)
        total = 0
        for right in range(len(nums)):
            total += nums[right]
            while total >= target:
                minLen = min(minLen,right-left+1)
                total -= nums[left]
                left += 1
        return minLen if minLen != float(inf) else 0
            
        