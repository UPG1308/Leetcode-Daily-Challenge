class Solution {
public:
    int bfs(int start, vector<vector<int>>& adj, int k){
        queue<int> q;
        q.push(start);
        vector<int> vis(adj.size());
        vis[start] = 1;
        int count = 0, level = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                if(level > k) return count;
                count++;
                for(int adjNode: adj[node]){
                    if(!vis[adjNode]) {
                        vis[adjNode] = 1;
                        q.push(adjNode);
                    }
                }
            }
            level++;
        }
        return count;
    }
    vector<vector<int>> adjList(vector<vector<int>>& edges){
        vector<vector<int>> adj(edges.size() + 1);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        auto adj1 = adjList(edges1), adj2 = adjList(edges2);
        int max1 = 0;
        for(int i = 0; i < m; ++i){
            max1 = max(max1, bfs(i, adj2, k - 1));
        }
        vector<int> ans(n, max1);
        for(int i = 0; i < n; ++i){
            ans[i] += bfs(i, adj1, k);
        }
        return ans;
    }
};
