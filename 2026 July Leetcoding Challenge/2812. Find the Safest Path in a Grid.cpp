class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> safetyFactor(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j]) safetyFactor[i][j] = 0, q.push({i, j});
            }
        }

        int val = 0;
        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, -1, 0, +1};

        auto boundaryCheck = [&](int r, int c){
            return r >= 0 && r < n && c >= 0 && c < m;
        };

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [row, col] = q.front(); q.pop();
                for(int i = 0; i < 4; ++i){
                    int r = row + delRow[i];
                    int c = col + delCol[i];
                    if(boundaryCheck(r, c) && safetyFactor[r][c] == -1){
                        safetyFactor[r][c] = val + 1;
                        q.push({r, c});
                    }
                }
            }
            val++;
        }
        
        priority_queue<array<int, 3>> pq;
        pq.push({safetyFactor[0][0], 0, 0});
        safetyFactor[0][0] = -1;
        while(!pq.empty()){
            auto [sf, row, col] = pq.top(); pq.pop();
            if(row == n - 1 && col == m - 1) return sf;
            for(int i = 0; i < 4; ++i){
                int r = row + delRow[i];
                int c = col + delCol[i];
                if(boundaryCheck(r, c) && safetyFactor[r][c] != -1){
                    pq.push({min(sf, safetyFactor[r][c]), r, c});
                    safetyFactor[r][c] = -1;
                }
            }
        }
        return -1;
    }
};
