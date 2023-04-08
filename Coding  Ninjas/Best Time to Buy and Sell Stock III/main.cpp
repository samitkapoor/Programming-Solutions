#include <bits/stdc++.h> 

int f(int i, int buy, vector<int>& prices, int n, int cap, vector<vector<vector<int>>>& dp) {
    if(cap == 0) return 0;
    if(i == n) return 0;

    if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

    if(buy) {
        return dp[i][buy][cap] = max(-prices[i] + f(i+1, 0, prices, n, cap, dp), 0 + f(i+1, 1, prices, n, cap, dp));
    } else {
        return dp[i][buy][cap] = max(prices[i] + f(i+1, 1, prices, n, cap-1, dp), 0 + f(i+1, 0, prices, n, cap, dp));
    }
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int i = n-1 ; i >= 0 ; i--) {
        for(int buy = 1 ; buy >= 0 ; buy--){
            for(int cap = 2 ; cap > 0 ; cap--){
                if(buy) {
                    dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], 0 + dp[i+1][1][cap]);
                } else {
                    dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], 0 + dp[i+1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][2];
}
