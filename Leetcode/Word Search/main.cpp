class Solution {
public:
    bool traverse(int i, int j, int count, vector<vector<char>>& board, string& word) {
        if(count == word.length()) return true;

        int m = board.size();
        int n = board[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        if(word[count] == board[i][j]) count++;
        else if(word[count] != board[i][j]) return false;

        char temp = board[i][j];
        board[i][j] = ' ';

        int answer = 
            traverse(i + 1, j, count, board, word) ||
            traverse(i, j + 1, count, board, word) ||
            traverse(i - 1, j, count, board, word) ||
            traverse(i, j - 1, count, board, word);

        board[i][j] = temp;

        return answer;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        bool answer = false;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) { 
                if(board[i][j] == word[0]) {
                    answer = answer || traverse(i, j, 0, board, word);
                    if(answer) return answer;
                }   
            }
        }

        return answer;
    }
};
