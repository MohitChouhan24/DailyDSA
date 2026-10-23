class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        prefix_map = {0: 1}
        prefix_sum = 0
        ans = 0

        for x in nums:
            prefix_sum = (prefix_sum + x) % k
            ans += prefix_map.get(prefix_sum, 0)
            prefix_map[prefix_sum] = prefix_map.get(prefix_sum, 0) + 1

        return ans