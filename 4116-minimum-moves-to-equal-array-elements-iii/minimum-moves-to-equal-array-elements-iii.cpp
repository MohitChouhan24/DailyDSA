class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = INT_MIN;
        for(int num : nums){
            m = max(m,num);
        }
        int ans = 0;
        for(int n : nums){
            ans += m-n;
        }
        return ans;
    }
};