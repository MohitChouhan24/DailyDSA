class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            long long currentProd = 1;
            long long currentGcd = nums[i];
            long long currentLcm = nums[i];
            for(int j = i; j < n; j++){
                if(currentProd >= LONG_MAX/nums[j]){
                    break;
                }
                else{
                    currentProd *= nums[j];
                }
                if(j > i){
                    currentGcd = gcd(currentGcd,nums[j]);
                    currentLcm = lcm(currentLcm,nums[j]);
                }
                if(currentProd == currentLcm*currentGcd){
                    maxLen = max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
    }
};