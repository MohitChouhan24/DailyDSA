class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            if nums[i] == 0:
                nums[i] = -1
        prefix_map = {0:-1}
        current_sum = 0
        max_len = 0
        for i, num in enumerate(nums):
            current_sum += num
            if current_sum in prefix_map:
                length = i - prefix_map[current_sum]
                max_len = max(max_len,length)
            else:
                prefix_map[current_sum] = i
        return max_len