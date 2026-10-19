class Solution(object):
    def targetIndices(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n):
            if(nums[i] == target):
                ans.append(i)
        
        return ans