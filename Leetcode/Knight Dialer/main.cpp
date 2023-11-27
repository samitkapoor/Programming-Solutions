class Solution {
public:
    int MOD = 1e9+7;
    int countMoves(unordered_map<int, vector<int>>& moves, int i, int n, vector<vector<int>>& memoization) {
        if(i == 5) return 0;
        if(n == 0) return 1;
        
        if(memoization[i][n] != -1) return memoization[i][n];

        int temp = 0;
        for(int j = 0 ; j < moves[i].size() ; j++){
            temp = (temp + countMoves(moves, moves[i][j], n-1, memoization))%(MOD);
        }

        return memoization[i][n] = temp;
    }

    int knightDialer(int n) {
        vector<vector<int>> memoization(10, vector<int>(n, -1));
        unordered_map<int, vector<int>> m;
        m[0] = {4,6};
        m[1] = {6,8};
        m[2] = {7,9};
        m[3] = {4,8};
        m[4] = {3,9,0};
        m[5] = {5};
        m[6] = {1,7,0};
        m[7] = {2,6};
        m[8] = {1,3};
        m[9] = {4,2};

        int moves = 0;
        for(int i = 0 ; i < 10 ; i++){
            moves = (moves + countMoves(m, i, n-1, memoization))%(MOD);
        }
        
        if(n == 1) moves++;

        return moves;
    }
};
