class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int row[] = new int[n];
        int col[] = new int[m];
        int [][]diff = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                diff[i][j] = row[i] + col[j] - (m - row[i] + n - col[j]);
            }
        }
        return diff;
    }
}
