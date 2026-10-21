class Solution:
    def search(self, nums: list[int], target: int) -> int:
        n = len(nums)
        s = 0
        e = n-1
        while s <= e:
            mid = s + (e-s)//2
            if nums[mid] == target:return mid
            elif nums[mid] < target : s = mid+1
            else : e = mid-1
        return -1 