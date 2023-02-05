class Solution {
public:
    bool isValid(char input, vector<vector<char>> board, int row, int col){
        for(int i = 0 ; i < board.size() ; i++){
            if(board[i][col] == input) return false;
            if(board[row][i] == input) return false;
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == input) return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[i].size() ; j++){
                if(board[i][j] == '.') {
                    for(char k = '1' ; k <= '9' ; k++){
                        if(isValid(k, board, i, j)){
                            board[i][j] = k;
                            bool val = solve(board);
                            if(val == false)
                                board[i][j] = '.';
                            else return true;

                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
