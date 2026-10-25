class Solution {
public:
    int m ,n;
    bool closed(vector<vector<int>>&grid,int i, int j){
        if(i >= m || i < 0 || j >= n || j < 0)return false;
        if(grid[i][j])return true;
        grid[i][j] = 1;
        bool down = closed(grid,i+1,j);
        bool up = closed(grid,i-1,j);
        bool right = closed(grid,i,j+1);
        bool left = closed(grid,i,j-1);

        return down && up && right && left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(),n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j])count += closed(grid,i,j);
            }
        }
        return count;
    }
};