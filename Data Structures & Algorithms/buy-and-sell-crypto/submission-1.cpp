class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int mx = 0;
        while( right< prices.size()){
            if(prices[right] - prices[left] > 0){
                mx = max(mx,prices[right]-prices[left]);
            }
            else{
                left = right;
            }
            right++;
        }
        return mx;
    }
};
