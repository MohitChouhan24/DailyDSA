class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temp_set = set(nums)
        ans = 0
        for val in temp_set:
            count = 1
            if val-1 not in temp_set:
                while val+1 in temp_set:
                    val = val+1
                    count = count+1
                ans = max(ans,count)
        return ans
        