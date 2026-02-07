class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> p(n + 1), suf(n + 1);
        for(int i = 0; i < n; ++i){
            p[i + 1] = p[i] + (s[i] == 'b');
        }
        for(int i = n - 1; i >= 0; --i){
            suf[i] = suf[i + 1] + (s[i] == 'a');
        }

        if(p[n] == 0 || suf[0] == 0) return 0;
        int ans = n;
        for(int i = 0; i <= n; ++i){
            ans = min(ans, p[i] + suf[i]);
        }
        return ans;
    }
};
