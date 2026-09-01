class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int maximum = 0;

        while(i<j){
            int contain = min(heights[i],heights[j]) * (j-i);
            maximum = max(maximum,contain);
            if(heights[i]<=heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maximum;
    }
};
