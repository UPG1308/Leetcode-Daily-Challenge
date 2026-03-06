class Solution {
public:
    bool checkOnesSegment(string s) {
        s = "0" + s;
        int cnt = 1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] != s[i - 1]) cnt++;
        }
        return (cnt == 2 || cnt == 3);
    }
};
