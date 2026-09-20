class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            int prod = (i+1) * (26-(s[i]-'a'));
            sum += prod;          
        }
        return sum;
    }
};