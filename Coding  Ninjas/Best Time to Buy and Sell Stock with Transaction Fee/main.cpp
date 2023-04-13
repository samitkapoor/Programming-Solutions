#include <bits/stdc++.h> 

int f(int i, int buy, vector<int> prices, int n, int fee, vector<vector<int>> &dp) {
    if(i == n) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];
         
    if(buy) {
        return dp[i][buy] = max(-prices[i] - fee + f(i+1, 0, prices, n, fee, dp), 0 + f(i+1, 1, prices, n, fee, dp));
    } else {
        return dp[i][buy] = max(prices[i] + f(i+1, 1, prices, n, fee, dp), f(i+1, 0, prices, n, fee, dp));
    }
}

int maximumProfit(int n, int fee, vector<int> &prices) {
    if(n == 1) return 0;
    
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int i = n-1 ; i >= 0 ; i--) {
        dp[i][1] = max(-prices[i] - fee + dp[i+1][0], dp[i+1][1]);
        dp[i][0] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
    }
    
    if(dp[0][1] < 0) {
        return 0;
    } else {
        return dp[0][1];
    }
}
