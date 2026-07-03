class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, long long>>> adj(n);
        vector<int> indegree(n);
        int l = -1, r = 1e9 + 1;
        for(auto it: edges){
            int u = it[0], v = it[1], w = it[2];
            indegree[v]++;
            adj[u].push_back(make_pair(v, w));
        }

        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> toposort;
        while(!q.empty()){
            int node = q.front(); q.pop();
            toposort.push_back(node);
            for(auto [adjNode, _]: adj[node]){
                if(--indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        
        auto check = [&](int m){
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;

            for(int i = 0; i < n; ++i){
                int node = toposort[i];
                if(dist[node] == LLONG_MAX || !online[node]) continue;
                for(auto [adjNode, w]: adj[node]){
                    if(!online[adjNode] || w < m) continue;
                    if(dist[adjNode] > dist[node] + w){
                        dist[adjNode] = dist[node] + w;
                    }
                }
            }
            return dist[n - 1] <= k;
        };

        while(r - l > 1){
            int m = l + (r - l)/2;
            if(check(m)) l = m;
            else r = m;
        }

        return l;
    }
};
