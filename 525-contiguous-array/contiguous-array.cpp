class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int current_sum = 0;
        int max_len = 0;
        unordered_map<int,int>prefix;
        prefix[0] = -1;
        for (int i = 0; i < n; i++){
            if(nums[i] == 0) current_sum += -1;
            else current_sum += 1;
            if(prefix.count(current_sum)){
                max_len = max(max_len,i-prefix[current_sum]);
            } 
            else{
                prefix[current_sum] = i;
            }
        }
        return max_len;
    }
};