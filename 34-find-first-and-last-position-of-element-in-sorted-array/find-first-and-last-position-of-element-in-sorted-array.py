class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        start = self.findBound(nums,target,find_lower = True)
        end = self.findBound(nums,target,find_lower = False)
        return [start,end]
    def findBound(self,nums: list[int], target : int, find_lower : bool):
        s = 0
        e = len(nums)-1
        ans = -1
        while s <= e:
            mid = s + (e-s)//2
            if nums[mid] ==  target:
                ans = mid
                if find_lower:
                    e = mid-1
                else:
                    s = mid+1
            elif nums[mid] < target:
                s = mid+1
            else: e = mid-1
        return ans
