class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        prefix_map = {0:1}
        sol = 0
        nums[0] = (nums[0]%k+k)%k
        prefix_map[nums[0]] = prefix_map.get(nums[0],0)+1
        if nums[0] == 0: sol += 1
        n = len(nums)
        for i in range(1,n):
            nums[i] = (((nums[i]+nums[i-1])%k)+k)%k
            sol += prefix_map.get(nums[i],0)
            prefix_map[nums[i]] = prefix_map.get(nums[i],0)+1
        
        return sol