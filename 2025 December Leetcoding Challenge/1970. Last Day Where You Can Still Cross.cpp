struct DSU{
    vector<int> parent, size, mark;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        mark.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        mark[u] = mark[v] = 1;
        u = find(u), v = find(v);
        if(u == v) return false;
        if(size[u] < size[v]) swap(u, v);
        size[u] += size[v];
        parent[v] = u;
        return true;
    }

    bool isSame(int u, int v){
        return find(u) == find(v);
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU dsu(row * (col + 2));
        auto getIndex = [&](int r, int c){
            return r * (col + 2) + c;
        };

        for(int i = 1; i < row; ++i){
            dsu.unite(getIndex(i, 0), getIndex(i - 1, 0));
            dsu.unite(getIndex(i, col + 1), getIndex(i - 1, col + 1));
        }

        int delRow[] = {+1, +1, 0, -1, -1, -1, 0, +1};
        int delCol[] = {0, -1, -1, -1, 0, +1, +1, +1};

        auto boundaryCheck = [&](int r){
            return r >= 0 && r < row;
        };

        for(int i = 0; i < cells.size(); ++i){
            int r = cells[i][0] - 1, c = cells[i][1];
            dsu.mark[getIndex(r, c)] = 1;
            for(int i = 0; i < 8; ++i){
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                if(boundaryCheck(nr) && dsu.mark[getIndex(nr, nc)]){
                    dsu.unite(getIndex(r, c), getIndex(nr, nc));
                }
            }
            if(dsu.isSame(0, col + 1)) return i;
        }
        return -1;
    }
};
