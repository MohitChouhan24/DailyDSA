class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int num : nums){
            map[num]++;
        }
        int n = nums.size();
        for(auto it : map){
            if(it.second > n/2)return it.first;
        }
        return 0;
    }
};