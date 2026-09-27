class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int n = s.length();
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == '('){
                st.push(i);
            }
            else if(c == ')'){
                int j = st.top();
                st.pop();
                reverse(s.begin()+j+1,s.begin()+i);
            }
        }
        string ans = "";
        for(char c : s){
            if(c != '(' && c != ')'){
                ans += c;
            }
        }
        cout << ans;
        return ans;
    }
};