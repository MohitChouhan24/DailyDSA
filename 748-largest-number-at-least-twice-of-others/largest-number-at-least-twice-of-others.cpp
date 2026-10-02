class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > largest){
                largest = nums[i];
                ans = i;
            }
        }
        cout << largest <<endl;
        cout << ans << endl;
        for(int i = 0; i < nums.size(); i++){
            if(i == ans)continue;
            if(2*nums[i] > largest)return -1;
        }
        return ans;
    }
};