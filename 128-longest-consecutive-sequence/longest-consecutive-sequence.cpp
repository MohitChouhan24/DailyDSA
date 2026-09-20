class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
        int maxCount = 0;
        for(int val : set){
            int count = 1;
            if(set.find(val-1) == set.end()){
                while(set.find(val+1) != set.end()){
                    count++;
                    val++;
                }
                maxCount = max(maxCount,count);
            }
        }
        return maxCount;
    }
};