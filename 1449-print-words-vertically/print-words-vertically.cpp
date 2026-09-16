class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string >words;
        int maxLen = INT_MIN;
        string word = "";
        for(char c : s){
            if(c == ' '){
                if(!word.empty()){
                    maxLen = max(maxLen, (int)word.length());
                    words.push_back(word);
                    word = "";
                }
            }
            else{
                word += c;
            }
        }
        if(!word.empty()){
            maxLen = max(maxLen,(int)word.length());
            words.push_back(word);
        }
        vector<string>ans(maxLen,"");
        for(int j = 0; j < maxLen; j++){
            for(string &w : words){
                if(j < w.length()){
                    ans[j] += w[j];
                }
                else{
                    ans[j] += ' '; 
                }
            }
        }
        for(string &word : ans){
            while(!word.empty() && word.back() == ' '){
                word.pop_back();
            }
        }
        return ans;
    }
};