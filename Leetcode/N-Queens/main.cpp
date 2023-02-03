class Solution {
public:
    bool canPlaceQueen(vector<string> board, int row, int col){
        int i = row;
        int j = col;
    
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            else i--, j--;
        }

        i = row;
        j = col;

        while(j >= 0){
            if(board[i][j] == 'Q') return false;
            else j--;
        }

        i = row;
        j = col;

        while(i < board.size() && j >= 0){
            if(board[i][j] == 'Q') return false;
            else i++, j--;
        }

        return true;
    }

    void placeQueens(int col, vector<vector<string>>& result, vector<string> board, int n){
        if(col == n){
            result.push_back(board);
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(canPlaceQueen(board, i, col)){
                board[i][col] = 'Q';
                placeQueens(col + 1, result, board, n);
                board[i][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);
        string row(n, '.');
        for(int i = 0 ; i < n ; i++){
            board[i] = row;
        }

        placeQueens(0, result, board, n);

        return result;
    }
};
