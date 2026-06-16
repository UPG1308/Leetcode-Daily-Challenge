class Solution {
public:
    string processStr(string s) {
        string str = "";
        for(char c: s){
            if(c >= 'a' && c <= 'z') str += c;
            else if(c == '*') {
                if(str.empty()) continue;
                str.pop_back();
            }
            else if(c == '#') str += str;
            else reverse(str.begin(), str.end());
        }
        return str;
    }
};
