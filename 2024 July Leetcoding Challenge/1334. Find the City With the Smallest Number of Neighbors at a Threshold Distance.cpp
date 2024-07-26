class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) mat[i][j] = 0;
            }
        }
        for(auto edge: edges){
            mat[edge[0]][edge[1]] = edge[2];
            mat[edge[1]][edge[0]] = edge[2];
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int ansCount = 1e3, ans = 0;
        for(int i = n - 1; i >= 0; i--){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] <= distanceThreshold) count++;
            }
            if(ansCount > count) ansCount = count, ans = i;
        }
        return ans;
    }
};
