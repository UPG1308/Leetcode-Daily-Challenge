class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, make_pair(INT_MIN, INT_MIN)));
        dp[0][0] = make_pair(0, 1);
        
        const int MOD = 1e9 + 7;
        int delRow[] = {0, +1, +1};
        int delCol[] = {+1, 0, +1};;
        auto boundaryCheck = [&](int r, int c){
            return r >= 0 && r < n && c >= 0 && c < m;
        };

        auto checkUpdate = [&](int r, int c, int nr, int nc){
            auto [score, count] = dp[r][c];
            if('0' <= board[nr][nc] && board[nr][nc] <= '9'){
                score += board[nr][nc] - '0';
            }
            if(dp[nr][nc].first < score) dp[nr][nc] = make_pair(score, count);
            else if(dp[nr][nc].first == score) dp[nr][nc].second = (dp[nr][nc].second + count) % MOD;
        };

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(dp[i][j] == make_pair(INT_MIN, INT_MIN)) continue;
                for(int k = 0; k < 3; ++k){
                    int row = i + delRow[k];
                    int col = j + delCol[k];
                    if(boundaryCheck(row, col) && board[row][col] != 'X'){
                        checkUpdate(i, j, row, col);
                    }
                }
            }
        }
        if(dp[n - 1][m - 1] == make_pair(INT_MIN, INT_MIN)) return vector<int>{0, 0};
        return vector<int>{dp[n - 1][m - 1].first, dp[n - 1][m - 1].second};
    }
};
