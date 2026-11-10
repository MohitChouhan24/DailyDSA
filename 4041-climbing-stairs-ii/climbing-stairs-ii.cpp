class Solution {
public:
    int n;
    vector<int>memo;
    int climb(vector<int>&costs,int i){
        if(i > n)return INT_MAX/2;
        if(i == n)return costs[n];
        if(!memo[i])
            memo[i] = costs[i] + min({climb(costs,i+1)+1,climb(costs,i+2)+4,climb(costs,i+3)+9});
        return memo[i];
    }
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(),0);
        vector<int>dp(n+3,INT_MAX/2);
        dp[n] = costs[n];
        for(int i = n-1; i >= 0; i--){
            dp[i] = costs[i] + min({dp[i+1]+1,dp[i+2]+4,dp[i+3]+9});
        }
        return dp[0];
    }
};