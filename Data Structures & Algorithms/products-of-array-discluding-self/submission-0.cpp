class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> result;
        for(int i=0;i<nums.size();i++){
            int sum = 1;
            for(int j=0;j<nums.size();j++){
                if(i == j) continue;
                sum*= nums[j];
            }   
            result.push_back(sum);
            sum = 1;
        }
        return result;
    }
};
