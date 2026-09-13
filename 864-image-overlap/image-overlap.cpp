class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>>image1;
        vector<pair<int,int>>image2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1)image1.push_back({i,j});
                if(img2[i][j] == 1)image2.push_back({i,j}); 
            }
        }
        if(image1.empty() || image2.empty())return 0;
        map<pair<int,int>,int>map;
        for(int i = 0; i < image1.size(); i++){
            for(int j = 0; j < image2.size(); j++){
                pair<int,int> translation = {image2[j].first-image1[i].first,image2[j].second-image1[i].second};
                map[translation]++;
            }
        }
        int ans = INT_MIN;
        for(auto t : map){
            if(ans < t.second){
                ans = t.second;
            }
        }
        return ans;
    }
};