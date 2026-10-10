class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums1.size(); i++) {
            map[abs(nums1[i] - nums2[i])]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto it : map) {
            if (it.first > 0) {
                pq.push({it.first, it.second});
            }
        }

        long long k = (long long)k1 + k2;

        while (k > 0 && !pq.empty()) {
            auto [largest, freq] = pq.top();
            pq.pop();

            int next = pq.empty() ? 0 : pq.top().first;
            long long cost = 1LL * (largest - next) * freq;

            if (cost <= k) {
                k -= cost;

                if (next > 0) {
                    auto p = pq.top();
                    pq.pop();
                    pq.push({p.first, p.second + freq});
                }
                
            } else {
                long long reduction = k / freq;
                long long remainder = k % freq;

                int newDiff = largest - reduction;

                if (newDiff > 0) {
                    pq.push({(int)newDiff, freq - (int)remainder});
                }

                if (remainder > 0) {
                    pq.push({(int)newDiff - 1, (int)remainder});
                }

                k = 0;
            }
        }

        long long ans = 0;

        while (!pq.empty()) {
            auto [diff, freq] = pq.top();
            pq.pop();

            ans += 1LL * diff * diff * freq;
        }

        return ans;
    }
};