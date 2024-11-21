class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<set<int>> rowWalls(m + 1), colWalls(n + 1), rowGuards(m + 1), colGuards(n + 1);
        vector<vector<bool>> unoccupied(m, vector<bool>(n, true));
        for(int i = 0; i < n; ++i){
            colWalls[i].insert(-1);
            colWalls[i].insert(m);
        }
        int safeCells = 0;
        for(int i = 0; i < m; ++i){
            rowWalls[i].insert(-1);
            rowWalls[i].insert(n);
        }
        for(vector<int> guard: guards){
            int row = guard[0], col = guard[1];
            unoccupied[row][col] = false;
            rowGuards[row].insert(col);
            colGuards[col].insert(row);
        }
        for(vector<int> wall: walls){
            int row = wall[0], col = wall[1];
            unoccupied[row][col] = false;
            rowWalls[row].insert(col);
            colWalls[col].insert(row);
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!unoccupied[i][j]) continue;
                auto right = rowWalls[i].upper_bound(j);
                auto left = right; --left;
                auto low = rowGuards[i].lower_bound(*left);
                if(low != rowGuards[i].end() && *low <= *right) continue;

                auto up = colWalls[j].upper_bound(i);
                auto down = up; --down;
                auto dow = colGuards[j].lower_bound(*down);
                if(dow != colGuards[j].end() && *dow <= *up) continue;
                safeCells++;
            }
        }
        return safeCells;
    }
};
