class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i = 0; i < n-3; i++){
            if(i > 0 && nums[i-1] == nums[i])continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && nums[j-1] == nums[j])continue;
                int left = j+1,right = n-1;
                long long int subTarget = (long long)target-nums[i]-nums[j];
                while(left < right){
                    long long int sum = nums[left]+nums[right];
                    if(sum > subTarget){
                        right--;
                    }
                    else if(sum < subTarget){
                        left++;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left-1] == nums[left])left++;
                        while(right > left && nums[right+1] == nums[right])right--;
                    }
                }
            }
        }
        return ans;
    }
};