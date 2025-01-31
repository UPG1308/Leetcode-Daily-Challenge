class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v){
        int upar = find(u);
        int vpar = find(v);

        if(upar == vpar) return false;

        if(size[upar] >= size[vpar]){
            size[upar] += size[vpar];
            parent[vpar] = upar;
        }
        else{
            size[vpar] += size[upar];
            parent[upar] = vpar;
        }
        return true;
    }
};

class Solution {
public:
    bool boundaryCheck(int row,int col, int n){
        return row >= 0 && row < n && col >= 0 && col < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), count = 1, maxCount = 1;
        int delRow[] = {0, +1, 0, -1};
        int delCol[] = {-1, 0, +1, 0};
        DisjointSet ds(n * n);
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                if(!grid[r][c]) continue;
                for(int i = 0; i < 4; ++i){
                    int row = r + delRow[i];
                    int col = c + delCol[i];
                    if(boundaryCheck(row, col, n) && grid[row][col]){
                        ds.unite(r * n + c, row * n + col);
                        maxCount = max(maxCount, ds.size[ds.find(r * n + c)]);
                    }
                }
            }
        }

        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                if(grid[r][c]) continue;
                int count = 1;
                unordered_set<int> seen;
                for(int i = 0; i < 4; ++i){
                    int row = r + delRow[i];
                    int col = c + delCol[i];
                    if(boundaryCheck(row, col, n) && grid[row][col]){
                        int upar = ds.find(row * n + col);
                        if(seen.find(upar) == seen.end()){
                            seen.insert(upar);
                            count += ds.size[upar];
                        }
                    }
                }
                maxCount = max(maxCount, count);
            }
        }
        return maxCount;
    }
};
