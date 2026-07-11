class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n);
        auto dfs = [&](auto &&self, int node, vector<int> &component) -> void{
            component.push_back(node);
            vis[node] = 1;
            for(int adjNode: adj[node]){
                if(!vis[adjNode]) self(self, adjNode, component);
            }
        };

        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                vector<int> component;
                dfs(dfs, i, component);
                int size = component.size(), complete = 1;
                for(int node: component){
                    if(adj[node].size() != size - 1) complete = 0;
                }
                ans += complete;
            }
        }
        return ans;
    }
};
