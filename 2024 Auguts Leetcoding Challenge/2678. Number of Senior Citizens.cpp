class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string s: details){
            if(s[11] >= '7') count++;
            else if(s[11] == '6' and s[12] > '0') count++;
        }
        return count;
    }
};
