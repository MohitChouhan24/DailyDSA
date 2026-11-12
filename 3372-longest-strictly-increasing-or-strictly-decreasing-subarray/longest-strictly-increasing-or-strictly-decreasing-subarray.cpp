class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int curr = 1;
        bool flag = true;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1] && flag){
                curr++;
            }
            else if(nums[i] > nums[i-1] && !flag){
                curr = 2;
                flag = true;
            }
            else if(nums[i] < nums[i-1] && !flag){
                curr++;
            }
            else if(nums[i] < nums[i-1] && flag){
                curr = 2;
                flag = false;
            }
            else if(nums[i] == nums[i-1]){
                curr = 1;
                flag = true;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};