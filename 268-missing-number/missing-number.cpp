class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            xorSum ^= nums[i] ^ i;
        }
        xorSum ^= n;
        return xorSum;
    }
};