class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 2, 0);
        dp[0] = 1;

        for(int len = 1; len <= high; ++len){
            dp[len] += (((len - one >= 0)? (dp[len - one] % mod): 0) +((len - zero >= 0)? (dp[len - zero] % mod):0));
            dp[len] %= mod;
        }
        int ans = 0;
        for(int len = low; len <= high; ++len){
            ans += dp[len];
            ans %= mod;
        }
        return ans;
    }
};
