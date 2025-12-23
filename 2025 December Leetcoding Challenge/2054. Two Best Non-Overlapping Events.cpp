class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        dp[0][0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= 2; ++j){
                if(dp[i][j] == -1) continue;
                int ub = upper_bound(events.begin() + i, events.end(), vector<int>{events[i][1], INT_MAX, INT_MAX}) - events.begin();
                if(j + 1 <= 2) dp[ub][j + 1] = max(dp[ub][j + 1], dp[i][j] + events[i][2]);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }

        return max(dp[n][1], dp[n][2]);
    }
};
