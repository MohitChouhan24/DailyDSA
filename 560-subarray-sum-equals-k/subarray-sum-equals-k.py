class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix =  {0:1}
        currentSum = 0
        ans = 0
        for x in nums :
            currentSum += x
            if currentSum-k in prefix:
                ans += prefix[currentSum-k]
            prefix[currentSum] = prefix.get(currentSum,0)+1
        return ans