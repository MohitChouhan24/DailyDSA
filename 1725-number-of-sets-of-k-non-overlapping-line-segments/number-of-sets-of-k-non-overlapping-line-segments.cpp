class Solution {
public:
    const int mod = 1e9+7;

    long long solve(int pos, int k, int open, int n,vector<vector<vector<long long>>>&dp){
         if(k < 0)return 0;
        if(pos == n)return k == 0 && open == 0;
       
        if(dp[pos][k][open] != -1)return dp[pos][k][open];
        long long ans = 0;
        if(open == 0){
            ans += solve(pos+1,k,0,n,dp);
            ans += solve(pos+1,k,1,n,dp);
        }
        else {
            ans += solve(pos+1,k,1,n,dp);
            ans +=solve(pos,k-1,0,n,dp);
        }
        return dp[pos][k][open] = ans%mod;
    }
    int numberOfSets(int n, int k) {
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(k+1,vector<long long>(2,-1)));
        return solve(0,k,0,n,dp);
    }
};