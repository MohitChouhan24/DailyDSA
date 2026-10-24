class Solution {
public:
    int days(const string& mmdd,int* before){
        return before[stoi(mmdd.substr(0,2))-1] + stoi(mmdd.substr(3)); 
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int before[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i = 1; i <= 12; i++){
            before[i] += before[i-1];
            cout << before[i] << " ";
        }
        return max(0,days(min(leaveAlice,leaveBob),before)-days(max(arriveAlice,arriveBob),before)+1);
    }
};