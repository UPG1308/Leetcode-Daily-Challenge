class Solution {
public:
    int searchNextIndex(vector<vector<int>> &events, int ind){
        int l = ind, r = events.size();
        while(r - l > 1){
            int m = l + (r - l)/2;
            if(events[m][0] > events[ind][1]) r = m;
            else l = m;
        }
        return r;
    }
    
    int maxValue(vector<vector<int>>& events, int K) {
        int n = events.size();
        sort(events.begin(), events.end(), [&](auto a, auto b){
            if(a[0] == b[0]) return a[2] > b[2];
            return a[0] < b[0];
        });
        vector<vector<int>> dp(n + 2, vector<int>(K + 2, -1));
        vector<int> nextIndex(n);
        for(int i = 0; i < n; ++i) nextIndex[i] = searchNextIndex(events, i);
        for(int i = 0; i <= n; ++i) dp[i][0] = 0;
        for(int i = 0; i <= n; ++i){
            for(int k = 0; k <= K && k <= i; ++k){
                if(dp[i][k] == -1) continue;
                int pick = 0, notpick = 0;
                int nextInd = nextIndex[i];
                if(i < n) dp[nextInd][k + 1] = max(dp[nextInd][k + 1], dp[i][k] + events[i][2]);
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
            }
        }
        int ans = 0;
        for(int k = 0; k <= K; ++k) ans = max(ans, dp[n][k]);
        return ans;
    }
};
