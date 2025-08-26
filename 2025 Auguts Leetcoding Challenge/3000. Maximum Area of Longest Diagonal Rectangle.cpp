class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long area = 0, diag = 0;
        for(auto it: dimensions){
            long long curarea = it[0] * it[1];
            long long curdiag = (it[0] * it[0]) + (it[1] * it[1]);
            if(curdiag > diag) {
                area = curarea;
                diag = (it[0] * it[0]) + (it[1] * it[1]);
            } else if(curdiag == diag) area = max(area, curarea);
        }
        return area;
    }
};
