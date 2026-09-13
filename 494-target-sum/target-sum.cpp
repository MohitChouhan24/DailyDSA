class Solution {
public:
    int solve(vector<int>&nums,int n, int target,vector<vector<int>>&dp){
        if(target < 0)return 0;
        if(n == 0)return target == 0;
        if(dp[n][target]!= -1)return dp[n][target];
        return dp[n][target] = solve(nums,n-1,target-nums[n-1],dp)+solve(nums,n-1,target,dp);
    }
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum+diff < 0 || (sum+diff)%2 != 0)return 0;
        int target = (sum+diff)/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(nums,n,target,dp);
    }
};