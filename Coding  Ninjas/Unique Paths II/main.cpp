int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(mat[i][j] != -1) {
              if (i == 0 && j == 0) {
                  dp[i][j] = 1;
              } else if (i == 0) {
                dp[i][j] = dp[i][j - 1];
              } else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
              } else {
                  dp[i][j] = (dp[i-1][j] + dp[i][j-1])%(1000000007);
              }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return dp[n-1][m-1];
}
