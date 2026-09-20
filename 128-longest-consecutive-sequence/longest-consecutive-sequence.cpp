class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 1;
        int i = 1;
        int len = 1;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 0)return 0;
        while(i < n){
            if(nums[i] == nums[i-1]+1){
                len++;
                maxLen = max(maxLen,len);
            }
            else if(nums[i] == nums[i-1]){}
            else{
                len = 1;
            }
            i++;
        }
        return maxLen;
    }
};