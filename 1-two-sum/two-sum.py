class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        map = {}
        n = len(nums)
        for i in range(n):
            c = target-nums[i]
            if c in map:
                return [i,map[c]]
            map[nums[i]] = i
        