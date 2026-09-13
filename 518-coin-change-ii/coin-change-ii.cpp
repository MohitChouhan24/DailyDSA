class Solution {
public:
    int solve(vector<int>&coins,int n , int amount,vector<vector<int>>&dp){
        if(n==0)return 0;
        if(amount == 0)return 1;
        if(dp[n][amount] != -1)return dp[n][amount];
        if(coins[n-1] > amount){
            return dp[n][amount] = solve(coins,n-1,amount,dp);
        }
        return dp[n][amount] = solve(coins,n,amount-coins[n-1],dp)+solve(coins,n-1,amount,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(n == 0)return 0;
        if(amount == 0)return 1;
        vector<vector<unsigned int>>dp(n+1,vector<unsigned int>(amount+1,-1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                if(j == 0)dp[i][j] = 1;
                if(i == 0)dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};