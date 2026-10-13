class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0)
            nums[i] = -nums[i];
        }
        sort(nums.rbegin(),nums.rend());
        vector<int>temp(n);
        int j = 0;
        for(int i = 0; i < n; i = i+2){
            temp[i] = nums[j++];
        }
        for(int i = 1; i < n; i = i+2){
            temp[i] = nums[j++];
        }
   
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                ans = ans + (long long)temp[i] * (long long)temp[i];
            }
            else{
                ans = ans - (long long)temp[i]*(long long)temp[i];
            }
        }
        return ans;
    }
};