class Solution {
public:
    unordered_set<string>ans;
    int maxLen = 0;
    void helper(string &s, int index, int balance,string& curr){
        if(index == s.size()){
            if(balance == 0){
                if(curr.length() > maxLen){
                    ans.clear();
                    maxLen = curr.length();
                    ans.insert(curr);
                }
                else if(curr.length() == maxLen){
                    ans.insert(curr);
                }
            }
            return;
        }
        if(s[index] == '('){
            helper(s,index+1,balance,curr);
            curr.push_back('(');
            helper(s,index+1,balance+1,curr);
            curr.pop_back();
        }
        else if(s[index] == ')'){
            helper(s,index+1,balance,curr);
            if(balance > 0){
                curr.push_back(')');
                helper(s,index+1,balance-1,curr);
                curr.pop_back();
            }
        }
        else{
            curr.push_back(s[index]);
            helper(s,index+1,balance,curr);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string curr = "";
        helper(s,0,0,curr);
        return vector<string>(ans.begin(),ans.end());
    }
};