class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(vector<int> edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;

        dfs(0, -1, adj, values, k, count);
        return count;
    }

    int dfs(int node, int parent, vector<int> adj[], vector<int>& values, int k, int& count){
        int sum = 0;
        for(int adjNode: adj[node]){
            if(adjNode == parent) continue;
            sum += dfs(adjNode, node, adj, values, k, count);
            sum %= k;
        }
        sum += values[node];
        sum %= k;
        if(sum == 0) count++;
        return sum;
    }
};
