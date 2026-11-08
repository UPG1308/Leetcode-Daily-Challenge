class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rowC(n), rowPos(n), colC(m);
        int total = 0, noc = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j]){
                    total++;
                    rowC[i]++;
                    rowPos[i] = j;
                    colC[j]++;
                }
            }
        }

        for(int i = 0; i < n; ++i){
            if(rowC[i] == 1 && colC[rowPos[i]] == 1) noc++;
        }
        return total - noc;
    }
};
