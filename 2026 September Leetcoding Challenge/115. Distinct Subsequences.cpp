class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {

                if (dp[i][j] == 0) continue;

                // Skip s[i]
                dp[i + 1][j] = min(
                    (long long)INT_MAX,
                    (long long)dp[i + 1][j] + dp[i][j]
                );

                // Take s[i]
                if (j < m && s[i] == t[j]) {
                    dp[i + 1][j + 1] = min(
                        (long long)INT_MAX,
                        (long long)dp[i + 1][j + 1] + dp[i][j]
                    );
                }
            }
        }

        return dp[n][m];
    }
};
