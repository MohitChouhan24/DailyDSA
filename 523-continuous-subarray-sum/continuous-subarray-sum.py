class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        prefix = {0:-1}
        currSum = 0
        n = len(nums)
        for i in range(n):
            currSum += nums[i]
            rem = currSum%k
            if rem in prefix:
                if i - prefix[rem] >= 2: return True
            else:
                prefix[rem] = i
        return False