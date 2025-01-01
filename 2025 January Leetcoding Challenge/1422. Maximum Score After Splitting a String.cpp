class Solution {
public:
    int maxScore(string s) {
        
        int n = s.size(), oneCount = 0;
        for(char c: s) oneCount += (c == '1');
        int one = 0, zero = 0, maxcount = 0;

        for(int i = 0; i < n - 1; ++i){
            zero += s[i] == '0';
            one += s[i] == '1';
            maxcount = max(maxcount, zero + oneCount - one);
        }
        return maxcount;
    }
};
