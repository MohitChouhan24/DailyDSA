class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string temp = "";
        while(num > 0){
            if(sum > 9){
                temp += '9';
                sum -= 9;
            }
            else{
                temp += to_string(sum);
                sum = 0;
            }
            num--;
        }
        return sum > 0 ? "" : temp;
    }
};