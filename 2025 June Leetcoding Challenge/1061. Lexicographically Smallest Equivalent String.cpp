struct DisjointSet{
    vector<int> size, parent;
    DisjointSet(){
        for(int i = 0; i < 26; ++i){
            size.push_back(1);
            parent.push_back(i);
        }
    }

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return false;
        if(size[u] < size[v]) swap(u, v);
        
        parent[v] = min(u, v);
        parent[u] = min(u, v);
        int s = size[u];
        size[u] += size[v];
        size[v] += s;
        return true;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds;
        for(int i = 0; i < s1.size(); ++i){
            ds.unite(s1[i] - 'a', s2[i] - 'a');
        }

        string s = "";
        for(char c: baseStr){
            s += char(ds.parent[ds.find(c - 'a')] + 'a');
        }
        return s;
    }
};
