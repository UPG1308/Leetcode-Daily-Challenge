class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0, neg = 0;
        int mn = abs(matrix[0][0]);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] < 0) neg = !neg;
                sum += 1LL * abs(matrix[i][j]);
                mn = min(mn, abs(matrix[i][j]));
            }
        }
        cout << mn << endl;
        return (neg)? sum - 2 * abs(mn): sum;
    }
};
