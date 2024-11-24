class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), minele = 1e7, negative = 0;
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] < 0) negative++;
                sum += abs(matrix[i][j]);
                minele = min(minele, abs(matrix[i][j]));
            }
        }
        if(negative & 1) return sum - 2 * minele;
        return sum;
    }
};
