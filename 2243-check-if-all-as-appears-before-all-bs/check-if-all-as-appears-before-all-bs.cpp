class Solution {
public:
    bool checkString(string s) {
        int a=-1;
        int b=s.length();
        for(int i=0; i < s.length(); i++){
            if(s[i] == 'a')a=max(a,i);
            if(s[i] == 'b')b = min(b,i);
        }
        return a < b;
    }
};