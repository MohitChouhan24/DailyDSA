class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int lvl = 0;
        int ans = 0;
        for(char c: s){
            if(c == '('){
                if(lvl == 1){
                    if(st.empty()){
                        ans += 2;
                    }
                    else{
                        ans += 1;
                        st.pop();
                    }
                    lvl = 0;
                }
                else if(lvl == 2){
                    if(st.empty()){
                        ans += 1;
                    }
                    else{
                        st.pop();
                    }
                    lvl = 0;
                }
                st.push('(');
            }
            else{
                lvl++;
                if(lvl == 2){
                    if(st.empty()){
                        ans += 1;
                    }
                    else{
                        st.pop();
                    }
                    lvl = 0;
                }
            }
        }
        if(lvl == 1){
            if(st.empty()){
                ans += 2;
            }
            else{
                ans += 1;
                st.pop();
            }
            lvl = 0;
        }
        return !st.empty() ? ans + 2*st.size() : ans;
    }
};