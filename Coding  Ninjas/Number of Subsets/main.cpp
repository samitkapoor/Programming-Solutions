#include <bits/stdc++.h> 

// for recursion approach with memoization
int f(int index, vector<int>& num, int tar, vector<vector<int>> &dp) {
    if(dp[index][tar] != -1) return dp[index][tar];

    if(tar == 0) return 1;

    if(index == 0) {
        if(tar == num[0]) return 1;
        else return 0;
    }


    int notTake = f(index-1, num, tar, dp);
    int take = 0;
    if(num[index] <= tar) {
        take = f(index-1, num, tar - num[index], dp);
    }

    return dp[index][tar] = take + notTake;
}

// tabulation method
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n+1, vector<int>(tar+1));

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= tar ; j++){
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= tar ; j++){
            if(num[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-num[i-1]];
            }
        }
    }

    return dp[n][tar];
}
