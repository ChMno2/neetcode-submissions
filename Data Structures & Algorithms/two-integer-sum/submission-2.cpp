class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> sub_map;
        for(int i=0 ;i<nums.size();i++){
            if(sub_map.find(target - nums[i]) != sub_map.end()){
                return {sub_map[target - nums[i]],i};
            }
            sub_map[nums[i]] = i;
        }
        return {};
    }
};
