class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3);
        int unique = 0, n = s.size(), ans = 0;
        for(int begin = 0, end = 0; end < n; ++end){
            unique += (++freq[s[end] - 'a'] == 1)? 1: 0;
            while(begin < end && unique == 3){
                ans += n - end;
                unique -= (--freq[s[begin++] - 'a'] == 0)? 1: 0;
            }
        }
        return ans;
    }
};
