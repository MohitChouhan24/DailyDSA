class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = INT_MAX;
        for(int num : nums){
            m = min(m,num);
        }
        int ans = 0;
        for(int n : nums){
            ans += n-m;
        }
        return ans;
    }
};