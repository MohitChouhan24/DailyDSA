class Solution {
public:
    int lower_bound(vector<int>&nums,int target,int n){
        int s = 0;
        int e = n-1;
        int ans = -1;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }   
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int start = lower_bound(nums,target,n);
        if(start == -1)return {};
        vector<int>ans;
        for(int i = start; i < n && nums[i]==target; i++){
            ans.push_back(i);
        }
        return ans;
    }
};