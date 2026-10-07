class Solution {
public:
    unordered_set<string>ans;
    void helper(string &s, int index, int leftRem,int rightRem,int balance,string& curr){
        if(index >= s.size()){
            if(balance == 0 && leftRem == 0 && rightRem == 0){
                ans.insert(curr);
            }
            return;
        }
        char ch = s[index];
        if(ch == '('){
            if(leftRem > 0){
                helper(s,index+1,leftRem-1,rightRem,balance,curr);
            }
            curr.push_back('(');
            helper(s,index+1,leftRem,rightRem,balance+1,curr);
            curr.pop_back();
        }
        else if(ch == ')'){
            if(rightRem > 0){
                helper(s,index+1,leftRem,rightRem-1,balance,curr);
            }
            if(balance > 0){
                curr.push_back(')');
                helper(s,index+1,leftRem,rightRem,balance-1,curr);
                curr.pop_back();
            }
        }
        else{
            curr.push_back(ch);
            helper(s,index+1,leftRem,rightRem,balance,curr);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0;
        int rightRem = 0;
        for(char& c : s){
            if(c == '(')leftRem++;
            else if(c == ')'){
                if(leftRem > 0)leftRem--;
                else rightRem++;
            }
        }
        string curr;
        helper(s,0,leftRem,rightRem,0,curr);
        return vector<string>(ans.begin(),ans.end());
    }
};