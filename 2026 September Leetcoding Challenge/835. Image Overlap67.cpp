class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int N = 3 * (n - 1) + 1;
        vector<vector<int>> grid(N, vector<int>(N));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                grid[i + n - 1][j + n - 1] = img1[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i + n - 1 < N; ++i){
            for(int j = 0; j + n - 1 < N; ++j){
                int count = 0;
                for(int k = 0; k < n; ++k){
                    for(int l = 0; l < n; ++l){
                        count += grid[i + k][j + l] && img2[k][l];
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
