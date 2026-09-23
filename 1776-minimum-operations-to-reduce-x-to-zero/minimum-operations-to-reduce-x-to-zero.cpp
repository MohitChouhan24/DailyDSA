class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        int maxLen = 0;
        int target = total-x;
        if(target < 0)return -1;
        if(target == 0)return n;
        int sum = 0;
        int i = 0;
        for(int j = 0; j < n; j++){
            sum += nums[j];
            while(sum >= target){
                if(sum == target){
                    maxLen = max(maxLen,j-i+1);
                }
                sum -= nums[i];
                i++;
            }
        }
        return maxLen == 0 ? -1 : n-maxLen;
    }
};