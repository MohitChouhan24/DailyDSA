class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>press;
        for(int i = 0; i <= rowIndex; i++){
            vector<int>curr(i+1,1);
            for(int j = 1; j < i; j++)curr[j] = press[j] + press[j-1];
            press = curr;
        }
        return press;
    }
};