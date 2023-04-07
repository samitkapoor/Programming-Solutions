#include<bits/stdc++.h>

long f(int i, int buy, long* values, int n, vector<vector<long>>& dp) {
    if(i == n) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];

    long profit = 0;
    if(buy) {
        profit = max(-values[i] + f(i+1, 0, values, n, dp), f(i+1, 1, values, n, dp));
    }
    else {
        profit = max(values[i] + f(i+1, 1, values, n, dp), f(i+1, 0, values, n, dp));
    }

    return dp[i][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1, vector<long>(2, 0));

    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 2 ; j++){
            long profit = 0;
            if(j) {
                profit = max(-values[i] + dp[i+1][0], dp[i+1][1]);
            } else {
                profit = max(values[i] + dp[i+1][1], dp[i+1][0]);
            }

            dp[i][j] = profit;
        }
    }

    return dp[0][1];
}
