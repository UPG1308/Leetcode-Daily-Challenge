class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), len = 0;
        vector<int> freq(26);

        for(int begin = 0, end = 0; end < n; ++end){
            freq[s[end] - 'a']++;
            while(begin <= end && freq[s[end] - 'a'] > 2){
                freq[s[begin++] - 'a']--;
            }
            len = max(len, end - begin + 1);
        }
        return len;
    }
};
