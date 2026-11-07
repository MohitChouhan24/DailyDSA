class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
        int ans = 0;
        for(int num : set){
            int count = 1;
            if(set.find(num-1) == set.end()){
                while(set.find(num+1) != set.end()){
                    count++;
                    num++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};