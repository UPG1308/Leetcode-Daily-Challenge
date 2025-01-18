class Solution {
public:
    bool boundaryCheck(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        int delRow[] = {0, 0, +1, -1};
        int delCol[] = {+1, -1, 0, 0};
        queue<pair<int,int>> q;
        q.push({0, 0});

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i){
                int r = row + delRow[i];
                int c = col + delCol[i];

                if(boundaryCheck(r, c, n, m) && (dist[r][c] > dist[row][col] + (i + 1 !=  grid[row][col]))){
                    dist[r][c] = dist[row][col] + (i + 1 != grid[row][col]);
                    q.push({r, c});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
