class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(K, 0)));
        dp[0][0][grid[0][0] % K] = 1;

        long long MOD = 1e9 + 7;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k < K; ++k){
                    if(dp[i][j][k] == 0) continue;
                    
                    if(i + 1 < n) dp[i + 1][j][(k + grid[i + 1][j]) % K] = (dp[i + 1][j][(k + grid[i + 1][j]) % K] % MOD + dp[i][j][k] % MOD) % MOD;

                    if(j + 1 < m) dp[i][j + 1][(k + grid[i][j + 1]) % K] = (dp[i][j + 1][(k + grid[i][j + 1]) % K] % MOD + dp[i][j][k] % MOD) % MOD;
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};
