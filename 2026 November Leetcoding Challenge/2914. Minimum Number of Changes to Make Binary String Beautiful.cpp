class Solution {
public:
    int minChanges(string s) {
        int n = s.size(), ans = 0;
        for(int i = 1; i < n; i += 2){
            ans += s[i] != s[i - 1];
        }
        return ans;
    }
};
