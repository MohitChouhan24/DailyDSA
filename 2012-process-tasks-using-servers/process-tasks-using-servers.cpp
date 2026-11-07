class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>available;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>unavailable;
        int n = servers.size();
        for(int i = 0; i < n; i++){
            available.push({servers[i],i});
        }
        long long time = 0;
        vector<int>ans(tasks.size());
        for(int i = 0; i < tasks.size(); i++){
            time = max(time,(long long)i);
            while(!unavailable.empty() && get<0>(unavailable.top()) <= time){
                auto[freetime,weight,index] = unavailable.top();
                unavailable.pop();
                available.push({weight,index});
            }
            if(available.empty()){
                time = get<0>(unavailable.top());
                while(!unavailable.empty() && get<0>(unavailable.top()) <= time){
                    auto[freetime,weight,index] = unavailable.top();
                    unavailable.pop();
                    available.push({weight,index});
                }
            }
            auto [weight,index] = available.top();
            available.pop();
            unavailable.push({time+tasks[i],servers[index],index});
            ans[i] = index;
        }
        return ans;
    }
};