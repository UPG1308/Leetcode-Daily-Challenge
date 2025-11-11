class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<int> one(N), zero(N);

        for(int i = 0; i < N; ++i){
            one[i] = count(strs[i].begin(), strs[i].end(), '1');
            zero[i] = count(strs[i].begin(), strs[i].end(), '0');
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        dp[0][0] = 0;
        int ans = 0;
        for(int i = 0; i < N; ++i){
            for(int j = n; j >= 0; --j){
                for(int k = m; k >= 0; --k){
                    if(dp[j][k] == -1) continue;
                    if(j + one[i] <= n && k + zero[i] <= m){
                        dp[j + one[i]][k + zero[i]] = max(dp[j + one[i]][k + zero[i]], dp[j][k] + 1);
                        ans = max(ans, dp[j + one[i]][k + zero[i]]);
                    }
                }
            }
        }

        return ans;
    }
};
