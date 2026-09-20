class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        for(int i = 0; i < n-1; i++){
            prefix[i+1] = prefix[i]*nums[i];
        }
        for(int i = n-1; i > 0; i--){
            suffix[i-1] = suffix[i]*nums[i];
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;
    }
};