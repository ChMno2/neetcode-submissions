class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        unordered_map<char,char> mp;
        mp['}'] = '{';
        mp[']'] = '[';
        mp[')'] = '(';
        for(auto & w:s){
            if(mp.count(w)){
                if(!stack.empty() && stack.top() == mp[w]){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else{
                stack.push(w);
            }
        }
        return stack.empty();
    }
};