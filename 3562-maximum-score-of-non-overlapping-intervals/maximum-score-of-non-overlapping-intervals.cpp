class Solution {
public:
    using P = pair<long long,vector<int>>;
    map<tuple<int,int,int>,int>originalIndex;
    vector<tuple<int,int,int>>intervals;
    vector<int>nextIndex;
    vector<vector<P>>dp;
    int n;
    P solve(int idx, int k){
        if(idx == n || k == 0){
            return {0,{}};
        }
        if(dp[idx][k].first != -1) return dp[idx][k];

        P skip = solve(idx+1,k);
        auto [left,right,weight] = intervals[idx];
        P take = solve(nextIndex[idx],k-1);
        take.first -= weight;
        take.second.push_back(originalIndex[{left,right,weight}]);
        sort(take.second.begin(),take.second.end());
        return dp[idx][k] = min(skip,take);
    }
    vector<int> maximumWeight(vector<vector<int>>& a) {
        for(int i = 0; i < a.size(); i++){
            if(originalIndex.find({a[i][0],a[i][1],a[i][2]}) != originalIndex.end())continue;
            originalIndex[{a[i][0],a[i][1],a[i][2]}] = i;
        }
        for(auto &[interval,index] : originalIndex){
            intervals.push_back(interval);
        }
        n = intervals.size();
        nextIndex.resize(n);
        for(int i = 0; i < n; i++){
            auto [left,right,weight] = intervals[i];
            nextIndex[i] = upper_bound(
                        intervals.begin(),
                        intervals.end(),
                        make_tuple(right,INT_MAX,INT_MAX)
                    )-intervals.begin();
        }
        dp.assign(n+1,vector<P>(5,{0,{}}));
        for(int i = n-1; i >= 0; i--){
            auto [left,right,weight] = intervals[i];
            int idx = originalIndex[{left,right,weight}];
            for(int k = 1; k <= 4; k++){
                P skip = dp[i+1][k];
                P take = dp[nextIndex[i]][k-1];
                take.first -= weight;
                take.second.push_back(idx);
                sort(take.second.begin(),take.second.end());
                dp[i][k] = min(skip,take);
            }
        }
        return dp[0][4].second;
    }
};