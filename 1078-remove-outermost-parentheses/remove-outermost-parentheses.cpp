class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int level = 0;
        for(auto & c : s){
            if((c == '(' && level++) || (c == ')' && --level))
                res += c;
        }
        return res;
    }
};