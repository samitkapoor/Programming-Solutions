class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        
        dp[0][0] = grid[0][0];
        
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0; j<grid[0].size() ; j++){
                
                //right
                if(j + 1 < grid[0].size()){
                    if(dp[i][j+1] == -1){
                        dp[i][j+1] = dp[i][j] + grid[i][j+1];
                    } else {
                        dp[i][j+1] = min(dp[i][j+1], dp[i][j] + grid[i][j+1]);
                    }
                }
                
                //down
                if(i + 1 < grid.size()){
                    if(dp[i+1][j] == -1){
                        dp[i+1][j] = dp[i][j] + grid[i+1][j];
                    } else {
                        dp[i+1][j] = min(dp[i+1][j], dp[i][j] + grid[i+1][j]);
                    }
                }
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
