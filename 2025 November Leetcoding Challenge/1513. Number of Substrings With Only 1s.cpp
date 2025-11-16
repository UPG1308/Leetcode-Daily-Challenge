class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long MOD = 1e9 + 7, ans = 0, cnt = 0;
        for(char c: s){
            if(c == '0'){
                ans = (ans + (cnt + 1) * cnt / 2) % MOD;
                cnt = 0;
            }
            else cnt++;
        }

        ans = (ans + (cnt + 1) * cnt / 2) % MOD;
        return ans;
    }
};
