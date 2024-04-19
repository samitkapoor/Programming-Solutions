class Solution {
public:
    void captureIsland(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(grid[i][j] == '0') return;

        grid[i][j] = '0';

        captureIsland(i+1, j, grid);
        captureIsland(i-1, j, grid);
        captureIsland(i, j+1, grid);
        captureIsland(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    captureIsland(i, j, grid);
                }
            }
        }

        return islands;
    }
};
