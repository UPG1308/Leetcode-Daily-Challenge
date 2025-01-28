class Solution {
public:
    
    bool boundaryCheck(int row, int col, int n, int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& count, int n, int m){
        vis[r][c] = true;
        int delRow[] = {0, -1, 0, +1};
        int delCol[] = {-1, 0, +1, 0};
        count += grid[r][c];
        for(int i = 0; i < 4; ++i){
            int row = r + delRow[i];
            int col = c + delCol[i];
            if(boundaryCheck(row, col, n, m) && grid[row][col] > 0 && !vis[row][col]){
                dfs(row, col, grid, vis, count, n, m);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxcount =0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!vis[i][j] && grid[i][j] > 0){
                    int count = 0;
                    dfs(i, j, grid, vis, count, n, m);
                    maxcount = max(maxcount, count);
                }
            }
        }
        return maxcount;
    }
};
