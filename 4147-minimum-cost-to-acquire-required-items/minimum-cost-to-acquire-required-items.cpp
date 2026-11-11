class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        ans += min((long long)need1,(long long)need2) * min((long long)cost1+(long long)cost2,(long long)costBoth);
        if(need1 == need2)return ans;
        else if(need1 > need2){
            need1 -= need2;
            ans += min((long long)cost1,(long long)costBoth)*(long long)need1;
        }
        else {
            need2 -= need1;
            ans += min((long long)cost2,(long long)costBoth)*(long long)need2;
        }
        return ans;
    }
};