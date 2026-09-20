class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>>set;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    set.insert({i,j});
                }
            }
        }
        for(auto [i,j] : set){
            for(int k = 0; k < n; k++){
                matrix[i][k] = 0;
            }
            for(int k = 0; k < m; k++){
                matrix[k][j] = 0;
            }
        }
    }
};