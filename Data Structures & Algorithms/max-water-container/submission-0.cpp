class Solution {
public:
    int maxArea(vector<int>& heights) {
        map<int ,int >mp;
        int n = heights.size();
        for(int i=0;i< n;i++){
            mp[i] = heights[i]; 
        }
        int mx = 0;
        for(int i=0;i<n-1;i++){
            for(int j=1;j<n;j++){
                mx = max(mx,(j-i) * min(mp[i],mp[j])); 
            }
        }
        return mx;
    }
};
