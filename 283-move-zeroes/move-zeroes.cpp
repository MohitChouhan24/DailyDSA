class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                int j = i;
                while(j < n && nums[j] == 0){
                    j++;
                }
                if(j != n)
                swap(nums[i],nums[j]);
            }
        }

    }
};