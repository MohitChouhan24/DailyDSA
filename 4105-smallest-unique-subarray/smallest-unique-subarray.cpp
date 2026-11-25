class Solution {
    long long Mod = 1e9+7;
    long long base = 100003;

    vector<long long>prefix_hash;
    vector<long long>power;
public:
    void hasher(vector<int>&arr){
        int n = arr.size();
        prefix_hash.resize(n+1,0);
        power.resize(n+1,1);

        for(int i = 0; i < n; i++){
            int val = (long long)arr[i];
            prefix_hash[i+1] = (prefix_hash[i]*base+val)%Mod;
            power[i+1] = (power[i]*base)%Mod;
        }
    }
    long long getHash(int l, int r){
        long long res = (prefix_hash[r+1]-(prefix_hash[l]*power[r-l+1])%Mod+Mod)%Mod;
        return res;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        hasher(nums);
        int n = nums.size();
        long long s = 0;
        long long e = n;
        int ans = n;
        while(s <= e){
            long long mid = s+(e-s)/2;
            unordered_map<long long,int>freq;
            long long l = 0;
            long long r = mid-1;
            while(r < n){
                long long hash = getHash(l,r);
                freq[hash]++;
                l++;
                r++;
            }
            bool isupdated = false;
            for(auto& hash : freq){
                if(hash.second == 1){
                    isupdated = true;
                    ans = min(ans,(int)mid);
                    e = mid-1;
                    break;
                }
            }
            if(!isupdated){
                s = mid+1;
            }
        }
        return ans;
    }
};