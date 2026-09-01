class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> ct(256,0);
        for(auto &tt:t){
            ct[tt] ++;
        }
        int counter = t.size();
        int left = 0;
        int right = 0;
        int min_start = 0;
        int req_len = INT_MAX;
        
        while(right < s.size()){
            if(ct[s[right]]>0){
                counter--;
            }
            ct[s[right]]--;
            right++;
            while(counter == 0){
                if(right - left < req_len){
                    min_start = left;
                    req_len = right - left;
                }
                ct[s[left]]++;
                if(ct[s[left]]>0){
                    counter++;
                }
                left++;
            }
        }
        return req_len == INT_MAX ? "" : s.substr(min_start,req_len);
    }
};
