class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int sol = 0;
        map[0]++;
        nums[0] = (nums[0]%k+k)%k;
        map[nums[0]]++;
        if(nums[0] == 0)sol++;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] = (((nums[i]+nums[i-1])%k)+k)%k;
            sol += map[nums[i]];
            map[nums[i]]++;
        }
        return sol;
    }
};