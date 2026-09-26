class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>map;
        for(auto &p : knowledge){
            map[p[0]] = p[1];
        }
        int n = s.length();
        for(int i = 0; i < s.length(); i++){
          if(s[i] == '('){
            int j = i+1;
            while(j < n  && s[j] != ')'){
                j++;
            }
            string key = s.substr(i+1,j-i-1);
            string val = "?";
            if(map.find(key) != map.end()){
                val = map[key];
            }
            s.replace(i,j-i+1,val);
          }
        }
        return s;
    }
};