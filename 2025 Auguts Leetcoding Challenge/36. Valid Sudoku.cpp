class Solution {
public:

    bool colCheck(int row, int col, vector<vector<char>>& board){
        for(int i = row + 1; i < 9; ++i){
            if(board[i][col] == board[row][col]) return true;
        }
        return false;
    }
    bool rowCheck(int row, int col, vector<vector<char>>& board){
        for(int j = col + 1; j < 9; ++j){
            if(board[row][j] == board[row][col]) return true;
        }
        return false;
    }

    bool checkSubMatrix(int row, int col, vector<vector<char>>& board){
        set<char> st;
        int count = 0;
        for(int i = row; i < row + 3; ++i){
            for(int j = col; j < col + 3; ++j){
                if(board[i][j] != '.'){
                    st.insert(board[i][j]);
                    count++;
                }
            }
        }
        return st.size() != count;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        for(int i = 0; i < n; ++i){
            for(int j = 0;j < n; ++j){
                if(board[i][j] != '.'){
                    if(rowCheck(i, j, board) || colCheck(i, j, board)) return false;
                }
            }
        }

        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){
                if(checkSubMatrix(row, col, board)) return false;
            }
        }
        return true;
    }
};
