class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        s = 0
        e = len(nums)-1
        while s < e:
            mid = s + (e-s)//2
            if nums[mid] > nums[mid+1]:
                e = mid
            else:
                s = mid+1
        return e