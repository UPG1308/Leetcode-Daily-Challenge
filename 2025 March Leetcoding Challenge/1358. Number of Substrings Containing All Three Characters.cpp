class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), count = 0, unique = 0;
        vector<int> freq(156, 0);
        for(int begin = 0, end = 0; end < n; ++end){
            unique += (freq[s[end]]++ == 0)?1:0;
            while(unique == 3){
                count += n - end;
                unique -= (freq[s[begin++]]-- == 1)?1:0;
            }
        }
        return count;
    }
};
