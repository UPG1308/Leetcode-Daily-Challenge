class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j <= min(n, i + 3); ++j){
                dp[j] = min(dp[j], dp[i] + costs[j - 1] + (j - i) * (j - i));
            }
        }
        return dp[n];
    }
};
