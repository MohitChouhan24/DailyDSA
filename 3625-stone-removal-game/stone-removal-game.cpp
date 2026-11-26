class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = false;
        int req = 10;
        while(n >= req){
            ans = !ans;
            n = n-req;
            req = req-1;
        }
        return ans;
    }
};