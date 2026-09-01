class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> feq_mp;
        for(auto & n:nums){
            feq_mp[n]++;
        }
        
        vector<vector<int>> buckets(nums.size()+1);
        for(auto & pair:feq_mp){
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> result;
        for(int i=nums.size();i>=0;i--){
            for(int num:buckets[i]){
                result.push_back(num);
                if(result.size()== k){
                    return result;
                }
            }
        }
        return result;
    }
};
