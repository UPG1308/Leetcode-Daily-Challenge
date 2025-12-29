class Solution {
public:
    int mp[26][26];

    bool backtrack(int i, int j, vector<vector<int>> &grid){
        if(i == 0) return true;
        if(i == j) {
            return backtrack(i - 1, 0, grid);
        }

        int mask = mp[grid[i][j]][grid[i][j + 1]];
        for(int c = 0; c < 6; ++c){
            if(mask >> c & 1) {
                grid[i - 1][j] = c;
                if(backtrack(i, j + 1, grid)) return true;
            }
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(mp, 0, sizeof(mp));
        for(string s: allowed){
            mp[s[0] - 'A'][s[1] - 'A'] |= 1 << (s[2] - 'A');
        }
        int n = bottom.size();
        vector<vector<int>> grid(n, vector<int>(n));
        for(int j = 0; j < n; ++j){
            grid[n - 1][j] = bottom[j] - 'A';
        }

        return backtrack(n - 1, 0, grid);
    }
};
