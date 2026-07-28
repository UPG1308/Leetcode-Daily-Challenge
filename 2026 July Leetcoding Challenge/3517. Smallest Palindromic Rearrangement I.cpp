class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> f(26);
        for(char c: s) f[c - 'a']++;

        string first = "", second = "";
        char middle = '-';
        for(int i = 0; i < 26; ++i){
            if(f[i] & 1) middle = char(i + 'a');
            int half = f[i] / 2;
            f[i] -= half;
            for(int j = 0; j < half; ++j) {
                first += char(i + 'a');
                second += char(i + 'a');
            }
        }
        reverse(second.begin(), second.end());
        if(middle == '-') return first + second;
        return first + middle + second;
    }
};
