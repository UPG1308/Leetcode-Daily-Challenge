class Solution {
    public int[][] findFarmland(int[][] land) {
        int n = land.length, m = land[0].length;
        int[][] grid = new int[n][m];
        int currentValue = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1){
                    if(i != 0 && land[i - 1][j] == 1) grid[i][j] = grid[i - 1][j];
                    else if(j != 0 && land[i][j - 1] == 1) grid[i][j] = grid[i][j - 1];
                    else grid[i][j] = currentValue++;
                }
            }
        }
        boolean vis[]= new boolean[currentValue];
        int ans[][] = new int[currentValue - 1][4];
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j] > 0 && !vis[grid[i][j]]){
                    vis[grid[i][j]] = true;
                    ans[grid[i][j] - 1][0] = i;
                    ans[grid[i][j] - 1][1] = j;
                }
                if(grid[i][j] > 0){
                    ans[grid[i][j] - 1][2] = i;
                    ans[grid[i][j] - 1][3] = j;
                }
            }
        }
        return ans;
    }
}
