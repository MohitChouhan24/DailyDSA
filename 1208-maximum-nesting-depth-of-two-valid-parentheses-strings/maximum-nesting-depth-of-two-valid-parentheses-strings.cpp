class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int>ans(n,-1);
        int balanceA = 0;
        int balanceB = 0;
        for(int i = 0; i < n; i++){
            char ch = seq[i];
            if(ch == '('){
                if(balanceA <= balanceB){
                    ans[i] = 0;
                    balanceA++;
                }
                else{
                    balanceB++;
                    ans[i] = 1;
                }
            }
            else{
                if(balanceA >= balanceB){
                    ans[i] = 0;
                    balanceA--;
                }
                else {
                    ans[i] = 1;
                    balanceB--;
                }
            }
        }
        return ans;
    }
};