class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int num : nums){
            if(num != nums[j]){
                j++;
                nums[j] = num;
            }
        }   
        return j+1;
    }
};