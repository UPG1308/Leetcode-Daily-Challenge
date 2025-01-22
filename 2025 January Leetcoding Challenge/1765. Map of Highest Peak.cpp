class Solution {
public:
    bool boundaryCheck(int row, int col, int n, int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e8));

        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(isWater[i][j]){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<int> delRow = {+1, 0, -1, 0};
        vector<int> delCol = {0, +1, 0, -1};

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i){
                int r = row + delRow[i];
                int c = col + delCol[i];
                if(boundaryCheck(r, c, n, m) && dist[row][col] + 1 < dist[r][c]){
                    dist[r][c] = 1 + dist[row][col];
                    q.push({r, c});
                }
            }
        }
        return dist;
    }
};
