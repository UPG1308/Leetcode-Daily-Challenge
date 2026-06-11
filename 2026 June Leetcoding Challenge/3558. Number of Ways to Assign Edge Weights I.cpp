class Solution {
public:
    const int MOD = 1e9 + 7;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        map<int, vector<int>> adj;
        map<int, int> vis;
        int n = 0;
        for(auto it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        function<void(int, int)> dfs = [&](int node, int par){
            vis[node] = vis[par] + 1;
            n = max(n, vis[node]);
            for(int adjNode: adj[node]){
                if(!vis.count(adjNode)){
                    dfs(adjNode, node);
                }
            }
        };
        dfs(1, -1);

        vector<vector<int>> dp(2, vector<int>(n + 1));
        dp[1][0] = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 2; ++j){
                for(int k = 0; k < 2; ++k){
                    dp[(j + k) % 2][i + 1] = (dp[(j + k) % 2][i + 1] + dp[j][i]) % MOD;
                }
            }
        }
        return dp[1][n - 1];
    }
};
