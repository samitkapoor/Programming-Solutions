class Solution {
public:
    int calculateGold(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] == 1 || grid[i][j] == 0) return 0;

        visited[i][j] = 1;

        int gold = 0;
        gold = max(gold, calculateGold(i + 1, j, visited, grid));
        gold = max(gold, calculateGold(i, j + 1, visited, grid));
        gold = max(gold, calculateGold(i - 1, j, visited, grid));
        gold = max(gold, calculateGold(i, j - 1, visited, grid));

        visited[i][j] = 0;

        return gold + grid[i][j];
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int gold = 0;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] != 0) {
                    int temp = 0;

                    vector<vector<int>> visited(m, vector<int>(n, 0));
                    temp = calculateGold(i, j, visited, grid);

                    gold = max(gold, temp);
                }
            }
        }

        return gold;
    }
};
