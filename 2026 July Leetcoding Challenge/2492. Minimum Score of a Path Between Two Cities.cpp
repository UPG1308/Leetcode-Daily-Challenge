class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it: roads){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        int val = 1e9;
        vector<bool> vis(n + 1);
        auto dfs = [&](auto &&self, int node) -> void{
            vis[node] = true;
            for(auto [adjNode, w]: adj[node]){
                val = min(val, w);
                if(vis[adjNode]) continue;
                self(self, adjNode);
            }
        };
        vis[1] = true;
        dfs(dfs, 1);
        return val;
    }
};
