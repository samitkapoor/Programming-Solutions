class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {\
        int n = grid.size();
        int m = grid[0].size();
        // toggle rows
        for(int i = 0 ; i < n ; i++) {
            if(grid[i][0] == 0) {
                // flip the row
                for(int j = 0 ; j < m ; j++) {
                    if(grid[i][j] == 1) grid[i][j] = 0;
                    else grid[i][j] = 1;
                }
            }
        }

        // toggle columns
        for(int i = 0 ; i < m ; i++) {
            int ones = 0;
            for(int j = 0 ; j < n ; j++) {
                if(grid[j][i] == 1) ones++;
            }

            if(ones <= n/2) {
                // flip the column
                for(int j = 0 ; j < n ; j++) {
                    if(grid[j][i] == 1) grid[j][i] = 0;
                    else grid[j][i] = 1;
                }
            }
        }

        // sum
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            int num = 0;
            for(int j = 0 ; j < m ; j++) {
                num += (grid[i][m-j-1] * pow(2, j));
            }
            sum += num;
        }

        return sum;
    }
};
