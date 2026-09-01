class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> window;
        int left =0;
        int LongestSubstring = 0;
        for(int right =0;right < s.size();right++){
            while(window.count(s[right])){
                //有抓到
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            LongestSubstring = max(LongestSubstring,right - left+1);
        }
        return LongestSubstring;
    }
};
