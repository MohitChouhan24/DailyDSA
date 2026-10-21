class Solution {
public:
    int minOperations(string s) {
        if(s.length() == 1)return 0;
        char mn = s[0],mx = s[0],prev=s[0];
        bool isSorted = true;
        int count1 = 1;
        int count2 = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] < prev){
               isSorted = false;
            }
            prev = s[i];
            if(mn == s[i])count1++;
            else if(s[i] < mn) count1 = 1;
            if(mx == s[i])count2++;
            else if(s[i] > mx) count2 = 1;
            mn = min(mn,s[i]);
            mx = max(mx,s[i]);
        }
        cout << isSorted << " " << mn  << " " << mx << endl;
        if(isSorted)return 0;
        if(s.length() == 2)return -1;
        if(mn == s[0] || mx == s[s.length()-1])return 1;
        cout << count1 << " " << count2 << endl;
        if(count1 == 1 && count2 ==1 && mx == s[0] && mn == s[s.length()-1])return 3;
        return 2;
    }
};