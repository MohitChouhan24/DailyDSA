class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int>first(26,n);
        vector<int>last(26,-1);
        for(int i = 0; i < n; i++){
            int ch = s[i]-'a';
            first[ch] = min(first[ch],i);
            last[ch] = i;
        }
       
        vector<pair<int,int>>possible;
        for(int i = 0; i < 26; i++){
            if(last[i] == -1){
                continue;
            }
            int l = first[i];
            int r = last[i];
            bool valid = true;
            for(int j = l; j <= r; j++){
                int ch = s[j]-'a';
                if(first[ch] < l){
                    valid = false;
                    break;
                }
                r = max(r,last[ch]);
            }
            if(valid){
                possible.push_back({l,r});
            }
        }
        sort(possible.begin(),possible.end(),[](const auto &a,const auto &b){
            return a.second< b.second; 
        });
    
        vector<string>ans;
        int lastEnd = -1;
        for(auto &[l,r] : possible){
            if(l > lastEnd){
                ans.push_back(s.substr(l,r-l+1));
                lastEnd = r;
            }
        }
        return ans;
    }
};