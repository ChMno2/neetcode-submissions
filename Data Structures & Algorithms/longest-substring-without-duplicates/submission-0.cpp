class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;

        while(right<s.size()){
            string subst = s.substr(left,right-left);
            size_t found_idx = subst.find(s[right]);
            if(found_idx!=string::npos){
                left = left + found_idx + 1;
            }
            max_len = max(max_len,right - left +1);
            right++;
        } 

        return max_len;
    }
};
