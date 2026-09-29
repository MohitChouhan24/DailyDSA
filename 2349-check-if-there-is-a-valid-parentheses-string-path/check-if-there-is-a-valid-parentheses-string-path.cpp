class Solution {
    bool helper(int balance, int r, int c, vector<vector<char>>& grid, int m, int n,vector<vector<vector<int>>>&dp) {
        if(balance < 0)return false;
        if(r == m-1 && c == n-1){
            if(grid[r][c] == '(')balance++;
            else balance--;
            return balance==0;
        }
        if(dp[r][c][balance] != -1)return dp[r][c][balance];

        char ch = grid[r][c];
        int newBalance = balance;
        if(ch == '('){
            newBalance++;
        }
        else {
            newBalance--;
        }
        if(newBalance < 0)return false;
        bool ans = false;
        if(r+1 < m){
            ans |= helper(newBalance,r+1,c,grid,m,n,dp);
        }
        if(c+1 < n){
            ans |= helper(newBalance,r,c+1,grid,m,n,dp);
        }
        return dp[r][c][balance] = ans;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxBalance = m+n;
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxBalance+1,-1)));
        return helper(0,0,0,grid,m,n,dp);
    }
};