class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> f(26);
        for(char c: text) f[c - 'a']++;
        int min_val = min(f['l' - 'a']/2, f['o' - 'a']/2);
        min_val = min({min_val, f['b' - 'a'], f['a' - 'a'], f['n' - 'a']});
        return min_val;
    }
};
