class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dp(26, vector<long long>(26, 1e9));
        for(int i = 0; i < original.size(); ++i){
            char s = original[i], t = changed[i];
            dp[s - 'a'][t - 'a'] = min(dp[s - 'a'][t - 'a'], 1LL * cost[i]);
        }

        for(int i = 0; i < 26; ++i) dp[i][i] = 0;
        for(int k = 0; k < 26; ++k){
            for(int i = 0; i < 26; ++i){
                for(int j = 0; j < 26; ++j){
                    if(dp[i][k] == 1e9 || dp[k][j] == 1e9) continue;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        long long ans = 0;
        for(int i = 0; i < source.size(); ++i){
            char s = source[i], t = target[i];
            if(dp[s - 'a'][t - 'a'] == 1e9) return -1;
            ans += dp[s - 'a'][t - 'a'];
        }

        return ans;
    }
};
