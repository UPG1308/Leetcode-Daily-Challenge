class Solution {
    int mini = (int) 1e5;
    public int minFallingPathSum(int[][] matrix) {
        int min = mini, n = matrix.length, m = matrix[0].length;
        int[] prev = new int[m], curr = new int[m];
        for(int i = 0; i < m; i++) prev[i] = matrix[n - 1][i];
        for(int row = n - 2; row >= 0; row--){
            for(int col = 0; col < m; col++){
                curr[col] = matrix[row][col] + Math.min(prev[col], Math.min(((col - 1 >= 0)? prev[col - 1]: mini), ((col + 1 < m)?prev[col + 1]:mini)));
                if(row == 0) min = Math.min(min, curr[col]);
            }
            prev = curr.clone();
        }
        return min;
    }
}
