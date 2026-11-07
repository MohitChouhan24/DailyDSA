class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>available;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>unavailable;
        vector<int>ans(tasks.size());
        long long time = 0;
        for(int i = 0; i < servers.size(); i++){
            available.push({servers[i],i});
        }
        for (int i = 0; i < tasks.size(); i++){
            time = max(time,(long long)i);
            while(!unavailable.empty() && get<0>(unavailable.top()) <= time){
                auto [freetime,weight,index] = unavailable.top();
                unavailable.pop();
                available.push({weight,index});
            }
            if(available.empty()){
                time = get<0>(unavailable.top());
                while(!unavailable.empty() && get<0>(unavailable.top()) <= time){
                    auto [freetime,weight,index] = unavailable.top();
                    unavailable.pop();
                    available.push({weight,index});
                }
            }
            auto [weight,index] = available.top();
            available.pop();
            ans[i] = index;
            unavailable.push({time+tasks[i],weight,index});
        }
        return ans;
    }
};