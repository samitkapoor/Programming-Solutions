class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid[0][0];
        
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
        
        for(int i = 0 ; i < n ; i++) {
            dp[1][i] = grid[n-1][i];
        }

        for(int i = n - 2 ; i >= 0 ; i--) {
            for(int j = n - 1 ; j >= 0 ; j--) {
                int mini = INT_MAX;
                for(int k = 0 ; k < n ; k++) {
                    if(k != j)
                        mini = min(mini, dp[1][k]);
                }
                dp[0][j] = mini + grid[i][j];
            }
            dp[1] = dp[0];
        }

        int ans = dp[0][0];
        for(int i = 0 ; i < n ; i++) {
            ans = min(ans, dp[0][i]);
        }

        return ans;
    }
};
