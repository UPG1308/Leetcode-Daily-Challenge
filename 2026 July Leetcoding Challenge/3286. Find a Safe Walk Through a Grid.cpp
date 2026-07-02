class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        deque<array<int, 3>> pq;
        if(health - grid[0][0] > 0)
            pq.push_back({health - grid[0][0], 0, 0});
        grid[0][0] = -1;

        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, -1, 0, +1};
        auto boundaryCheck = [&](int r, int c){
            return r >= 0 && r < n && c >= 0 && c < m;
        };
        while(!pq.empty()){
            auto [h, r, c] = pq.front(); pq.pop_front();
            if(r == n - 1 && c == m - 1){
                return true;
            }
            for(int i = 0; i < 4; ++i){
                int row = r + delRow[i];
                int col = c + delCol[i];

                if(boundaryCheck(row, col) && grid[row][col] != -1 && h - grid[row][col] > 0){
                    if(grid[row][col] == 0) pq.push_front({h, row, col});
                    else pq.push_back({h - 1, row, col});
                    grid[row][col] = -1;
                }
            }
        }
        return false;
    }
};
