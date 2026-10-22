class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        ans = []
        n = len(nums)
        nums.sort()
        for i in range(n-1):
            if i > 0 and nums[i-1] == nums[i]: continue
            left = i+1
            right = n-1
            while left < right:
                sum = nums[left] + nums[right] + nums[i]
                if(sum < 0):
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    ans.append([nums[i],nums[left],nums[right]])
                    left+=1
                    right-=1
                    while left < right and nums[left] == nums[left-1] : left +=1
                    while right > left and nums[right] == nums[right+1] : right -= 1
        return ans