class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        for(char c: s) freq[c - 'a']++;
        int count = 0;
        for(int i = 0; i < 26; ++i){
            if(freq[i]) count += ((freq[i] - 1) % 2) + 1;
        }
        return count;
    }
};
