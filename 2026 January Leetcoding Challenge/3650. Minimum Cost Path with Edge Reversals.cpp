class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto it: edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, 2 * w));
        }

        vector<int> dist(n, 1e8);
        dist[0] = 0;
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push(make_pair(0, 0));

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            if(dist[node] != dis) continue;
            for(auto [adjNode, weight]: adj[node]){
                if(dist[adjNode] > dist[node] + weight){
                    dist[adjNode] = dist[node] + weight;
                    pq.push(make_pair(dist[adjNode], adjNode));
                }
            }
        }

        return dist[n - 1] == 1e8? -1: dist[n - 1];
    }
};
