class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size()*grid.size();
        long long actualSum = 0;
        long long actualSquareSum = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                actualSum += grid[i][j];
                actualSquareSum += 1LL * grid[i][j] * grid[i][j];
            }
        }
        long long sum = n * (n+1)/2;
        long long squareSum = n * (n+1) * (2*n+1)/6;

        long long diff = actualSum - sum;
        long long squareDiff = actualSquareSum - squareSum;

        long long sumAB = squareDiff/diff;
        long long A = (diff+sumAB)/2;
        long long B = sumAB-A;
        return {(int)A,(int)B};
    }
};