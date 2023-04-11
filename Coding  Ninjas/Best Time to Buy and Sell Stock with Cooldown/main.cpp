#include <bits/stdc++.h> 

// recursion with memoization
int f(int i, int buy, vector<int>& prices, vector<vector<int>> &dp) {
    if(i >= prices.size()) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];

    if(buy) {
        return dp[i][buy] = max(-prices[i] + f(i+1, 0, prices, dp), 0 + f(i+1, 1, prices, dp));
    } 
    return dp[i][buy] = max(prices[i] + f(i+2, 1, prices, dp), 0 + f(i+1, 0, prices, dp));
}

// tabulation method
int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    for(int i = n-1 ; i >= 0 ; i--) {
        for(int j = 0 ; j <= 1 ; j++){
            if(j) {
                dp[i][j] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            } else {
                dp[i][j] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
            }
        }
    }

    return dp[0][1];
}
