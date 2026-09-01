class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string &s:strs){
            encoded += to_string(s.length()) + "#" + s; //3#cat
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int  i = 0;
        while(i < s.size()){
            // s.find('#', i) 代表從索引值 i 開始往後找 '#'
            int delimPos = s.find("#",i);
            int length = stoi(s.substr(i,delimPos-i));

            string str = s.substr(delimPos+1,length);
            decoded.push_back(str);
            i = delimPos + 1 + length;

        }
        return decoded;
    }
};
