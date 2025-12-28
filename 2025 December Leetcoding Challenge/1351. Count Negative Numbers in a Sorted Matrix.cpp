class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = m - 1, ans = 0;
        do{
            if(grid[i][j] < 0){
                if(j == 0){
                    ans += m;
                    i++;
                } else j--;
            } else ans += (m - j - 1), i++;
        } while(i != n);
        return ans;
    }
};
