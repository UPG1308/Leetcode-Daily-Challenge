class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), len = 0;
        vector<int> freq(256, 0);
        for(char c: s) freq[c]++;
        if(freq['a'] < k || freq['b'] < k || freq['c'] < k) return -1;

        for(int begin = 0, end = 0; end < n; ++end){
            freq[s[end]]--;
            while(freq['a'] < k || freq['b'] < k || freq['c'] < k){
                freq[s[begin++]]++;
            }
            len = max(len, end - begin + 1);
        }
        return n - len;
    }
};
