class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for(int i = 1; i < s.length(); i++){
            if( i%2 && s[i] != s[i-1]){
                ans++;
            }
        }
        return ans;
    }
};