class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        int rows = grid.size(), cols = grid[0].size();

        vector<pair<int, int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for(int i = 0 ; i < rows ; i++) {
            for(int j = 0 ; j < cols ; j++) {
                if(grid[i][j] == 1) {
                    for(int d = 0 ; d < 4 ; d++) {
                        int di = directions[d].first + i;
                        int dj = directions[d].second + j;

                        if(!(di >= 0 && dj >= 0 && di < rows && dj < cols && grid[di][dj] == 1)) {
                            perimeter++;
                        }
                    }
                }
            }
        }

        return perimeter;
    }
};
