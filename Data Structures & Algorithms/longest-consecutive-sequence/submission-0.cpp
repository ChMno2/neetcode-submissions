class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_seq;
        for(auto &n:nums){
            set_seq.insert(n);
        }
        int mx=0;
        for(auto &n:nums){
            if(set_seq.find(n-1)==set_seq.end()){
                int t = n+1;
                int sum =1;
                while(set_seq.find(t)!=set_seq.end()){
                    sum++;
                    t++;
                }
                mx = max(mx,sum);
            }
        }
        return mx;

    }
};
