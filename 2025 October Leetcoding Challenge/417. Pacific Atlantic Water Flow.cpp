class Solution {
public:
    vector<int> delRow{+1, 0, -1, 0};
    vector<int> delCol{0, -1, 0, +1};

    bool boundaryCheck(int row, int col, int n, int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void bfs(int sr, int sc, vector<vector<int>>& heights, vector<vector<vector<int>>>& grid, int ind, vector<vector<vector<bool>>>& vis){
        int n = heights.size(), m = heights[0].size();
        queue<vector<int>> q;
        q.push({sr, sc});
        vis[sr][sc][ind] = true;

        while(!q.empty()){
            int r = q.front()[0], c = q.front()[1], curval = heights[q.front()[0]][q.front()[1]];
            grid[r][c][ind] = 1;

            q.pop();

            for(int i = 0; i < 4; ++i){
                int row = r + delRow[i];
                int col = c + delCol[i];
                if(boundaryCheck(row, col, n, m) && curval <= heights[row][col] && !vis[row][col][ind]){
                    grid[row][col][ind] = 1;
                    vis[row][col][ind] = true;
                    q.push({row, col});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<vector<int>>> grid(n, vector<vector<int>>(m, vector<int>(2, 0)));
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(2, false)));

        for(int i = 0; i < n; ++i){
            if(!vis[i][0][0]) bfs(i, 0, heights, grid, 0, vis);
            if(!vis[i][m - 1][1]) bfs(i, m - 1, heights, grid, 1, vis);
        }

        for(int j = 0; j < m; ++j){
            if(!vis[0][j][0]) bfs(0, j, heights, grid, 0, vis);
            if(!vis[n - 1][j][1]) bfs(n - 1, j, heights, grid, 1, vis);
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j][0] && grid[i][j][1]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};
