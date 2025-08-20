class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int left = 0, up = 0, diag = 0;
                if(i - 1 >= 0) up = matrix[i - 1][j];
                if(j - 1 >= 0) left = matrix[i][j - 1];
                if(i - 1 >= 0 && j - 1 >= 0) diag = matrix[i - 1][j - 1];
                if(matrix[i][j] == 1){
                    matrix[i][j] = min({left, up, diag}) + 1;
                    ans += matrix[i][j];
                }
            }
        }
        return ans;
    }
};
