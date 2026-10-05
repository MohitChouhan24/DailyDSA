class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char ch : s){
            if(ch == '('){
                st.push(0);
            }
            else{
                int temp = st.top(); st.pop();
                int ans = temp == 0 ? 1 : 2*temp;
                st.top() += ans;
            }
        }
        return st.top();
    }
};