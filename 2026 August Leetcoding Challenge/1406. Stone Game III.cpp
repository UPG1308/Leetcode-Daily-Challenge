class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, -1e9));
        dp[0][n] = dp[1][n] = 0;
        for(int i = n - 1; i >= 0; --i){
            for(int j = 0; j < 2; ++j){
                dp[j][i] = max(dp[j][i], stoneValue[i] - dp[j ^ 1][i + 1]);
                if(i + 2 <= n) dp[j][i] = max(dp[j][i], stoneValue[i] + stoneValue[i + 1] - dp[j ^ 1][i + 2]);
                if(i + 3 <= n) dp[j][i] = max(dp[j][i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[j ^ 1][i + 3]);
            }
        }

       if(dp[0][0] == 0) return "Tie";
       return dp[0][0] < 0? "Bob": "Alice";
    }
};
