class Solution {
    public boolean exist(char[][] board, String word) {
        int n = board.length, m = board[0].length;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word.charAt(0)){
                    if(dfs(i, j, 0, word, new boolean[n][m], board, n, m)) return true;
                }
            }
        }
        return false;
    }
    public boolean dfs(int ro, int co, int ind, String word, boolean [][]vis, char[][] board, int n, int m){
        if(ind == word.length() - 1) return true;
        vis[ro][co] = true;
        int[] delRow = {+1,0, -1, 0};
        int[] delCol = {0, -1, 0, +1};
        for(int i = 0; i < 4; i++){
            int row = ro + delRow[i];
            int col = co + delCol[i];
            if(boundaryCheck(row, col, n, m) && (word.charAt(ind + 1) == board[row][col]) && !vis[row][col]){
                if(dfs(row, col, ind + 1, word, vis, board, n, m)) return true;
            }
        }
        vis[ro][co] = false;
        return false;
    }
    public boolean boundaryCheck(int row, int col, int n, int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }
}
