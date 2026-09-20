class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        for(auto temp : strs){
            string last = temp;
            sort(temp.begin(),temp.end());
            map[temp].push_back(last);
        }
        vector<vector<string>>ans;
        for(auto &it : map){
            ans.push_back(it.second);
        }
        return ans;
    }
};