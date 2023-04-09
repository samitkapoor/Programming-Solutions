#include <bits/stdc++.h> 

int f(int i, int buy, int k, vector<int> &prices, int n, vector<vector<vector<int>>>& dp) {
    if(k == 0 || i == n) return 0;

    if(dp[i][buy][k] != -1) return dp[i][buy][k];
    
    if(buy == 1) {
        return dp[i][buy][k] = max(-prices[i] + f(i+1, 0, k, prices, n, dp), 0 + f(i+1, 1, k, prices, n, dp));
    }
    return dp[i][buy][k] = max(prices[i] + f(i+1, 1, k-1, prices, n, dp), 0 + f(i+1, 0, k, prices, n, dp));
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    for(int i = n-1 ; i >= 0 ; i--) {
        for(int buy = 0 ; buy < 2 ; buy++) {
            for(int cap = k ; cap > 0 ; cap--) {
                if(buy) {
                    dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]); 
                } else {
                    dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][k];
}
