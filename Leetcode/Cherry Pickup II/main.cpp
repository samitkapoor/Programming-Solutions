class Solution {
public:
    int helper(int i, int j, int y, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        //check out of bounds
        if(i >= grid.size() || j < 0 || j >= grid[0].size() || y < 0 || y >= grid[0].size()){
            return 0;
        }
        if(i == grid.size()) {
            if(j != y)
                return grid[i][j] + grid[i][y];
            else 
                return grid[i][j];
        }

        if(dp[i][j][y] != -1) return dp[i][j][y];

        vector<vector<int>> moves{{1, -1}, {1, 0}, {1, 1}};
        int answer = 0;
        
        for(int m = 0 ; m < 3 ; m++) {
            int di = i + moves[m][0];
            int dj = j + moves[m][1];

            for(int n = 0 ; n < 3 ; n++) {
                int dx = i + moves[n][0];
                int dy = y + moves[n][1];
                
                if(j == y) {
                    answer = max(answer, grid[i][j] + helper(di, dj, dy, grid, dp));
                } else {
                    answer = max(answer, grid[i][j] + grid[i][y] + helper(di, dj, dy, grid, dp));
                }
            }
        }

        return dp[i][j][y] = answer;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return helper(0, 0,  grid[0].size()-1, grid, dp);
    }
};
