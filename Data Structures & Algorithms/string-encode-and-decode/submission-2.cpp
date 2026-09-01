class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(auto &s:strs){
            enc += to_string(s.size())+"#"+s; //3#cat5#apple
        }
        return enc;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> result;
        while(i < s.size()){
            int idx = s.find("#",i);
            int length = stoi(s.substr(i,idx - i));//1 or 12
            result.push_back(s.substr(idx+1,length));
            i = idx + length +1;
        }
        return result;
    }
};
