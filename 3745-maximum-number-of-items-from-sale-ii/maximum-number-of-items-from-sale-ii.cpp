
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        int mn = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            mn = min(mn, item[1]);
        }

        vector<int> mul(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                mul[i] += freq[j];
            }
        }

        vector<pair<int, int>> deals;

        for (auto& item : items) {
            int fact = item[0];
            int pri = item[1];

            int gifts = mul[fact] - 1;

            if (gifts > 0 && pri < 2LL * mn) {
                deals.push_back({pri, gifts});
            }
        }

        sort(deals.begin(), deals.end());

        long long ans = 0;

        for (auto& deal : deals) {
            int pri = deal.first;
            int gifts = deal.second;

            long long buy = min(
                (long long)gifts,
                (long long)budget / pri
            );

            ans += buy * 2;
            budget -= buy * pri;
        }

        ans += budget / mn;

        return (int)ans;
    }
};