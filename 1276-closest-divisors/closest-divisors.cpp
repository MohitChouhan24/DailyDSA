class Solution {
public:
    vector<int> closestDivisors(int num) {
        int num1 = num+1,num2 = num+2,dist = INT_MAX;
        vector<int>result;
        for(int i = sqrt(num2); i>= 1; i--){
            if(num2%i == 0){
                result = {i,num2/i};
                dist = num2/i-i;
                break;
            }
        }
        for(int i = sqrt(num1); i >= 1; i--){
            if(num1%i == 0){
                if(num1/i-i < dist){
                    result = {i,num1/i};
                    break;
                }
            }
        }
        return result;
    }
};