class Solution {
public:
    int dfs(int node, int par, const vector<vector<int>>& adj, vector<int>& parity, int even = 1){
        parity[node] = even;
        int total = even;
        for(int adjNode: adj[node]){
            if(adjNode == par) continue;
            total += dfs(adjNode, node, adj, parity,  1 - even);
        }
        return total;
    }

    vector<vector<int>> adjList(vector<vector<int>>& edges){
        vector<vector<int>> adj(edges.size() + 1);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> first(n), second(m), ans(n);
        int even1 = dfs(0, -1, adjList(edges1), first), odd1 = n - even1;
        int even2 = dfs(0, -1, adjList(edges2), second), odd2 = m - even2;
        for(int i = 0; i < n; ++i){
            ans[i] = max(even2, odd2) + (first[i]? even1: odd1);
        }
        return ans;
    }
};
