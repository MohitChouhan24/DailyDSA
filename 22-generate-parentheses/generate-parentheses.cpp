class Solution {
public:
    bool isValid(string s){
        stack<char>st;
        for(int ch : s){
            if(ch == '('){
                st.push('(');
            }
            else{
                if(st.empty())return false;
                else if(ch == ')' && st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    void solve(string s , int index,vector<string>&ans){
        if(index >= s.size()){
            if(isValid(s)){
                ans.push_back(s);
            }
            return;
        }
        unordered_set<char>used;
        for(int i = index; i < s.length(); i++){
            if(used.count(s[i]))continue;
            used.insert(s[i]);
            swap(s[i],s[index]);
            solve(s,index+1,ans);
            swap(s[i],s[index]);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        for(int i = 0; i < n; i++){
            s += '(';
            s += ')';
        }
        vector<string>ans;
        solve(s,0,ans);
        return ans;
    }
};