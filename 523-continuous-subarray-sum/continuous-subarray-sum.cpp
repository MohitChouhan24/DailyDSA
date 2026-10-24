class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        prefix[0] = -1;
        nums[0] = nums[0]%k;
        if(nums[0] != 0)
        prefix[nums[0]] = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] = (nums[i]+nums[i-1])%k;
            if(prefix.count(nums[i]) && i-prefix[nums[i]] >= 2){
                return true;
            }
            else if(!prefix.count(nums[i]))
            prefix[nums[i]] = i;
        }
        return false;
    }
};