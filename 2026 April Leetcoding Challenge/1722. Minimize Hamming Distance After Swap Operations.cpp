struct DSU{
    vector<int> size, parent;
    int n;
    DSU(int _n){
        n = _n;
        size.resize(n, 1);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        if(size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        for(int i = 0; i < allowedSwaps.size(); ++i){
            int u = allowedSwaps[i][0], v = allowedSwaps[i][1];
            dsu.unite(u, v);
        }

        int ans = n;
        vector<multiset<int>> mt(n);

        for(int i = 0; i < n; ++i){
            int p = dsu.find(i);
            mt[p].insert(source[i]);
        }
        for(int i = 0; i < n; ++i){
            int p = dsu.find(i);
            if(mt[p].count(target[i])){
                mt[p].erase(mt[p].find(target[i]));
                ans--;
            }
        }
        return ans;
    }
};
