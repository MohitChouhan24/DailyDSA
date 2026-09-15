class Solution {
public:
    bool isPalindrome(string s){
        int i = 0; 
        int j = s.length()-1;
        while(i <= j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string s,int k, int i, int j,vector<vector<int>>&dp){
        if(j-i+1 > k+1)return 0;
        if(i >= s.length() || j >= s.length()){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(isPalindrome(s.substr(i,j-i+1))){
            return dp[i][j] = 1+solve(s,k,j+1,j+k,dp);
        }
        return dp[i][j] = max(solve(s,k,i+1,j+1,dp),solve(s,k,i,j+1,dp));
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,k,0,k-1,dp);
    }
};