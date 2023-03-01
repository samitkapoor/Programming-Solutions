#include <bits/stdc++.h> 

bool f(int index, int k, vector<int>& arr, vector<vector<int>> &dp) {
    if(k == 0) return true;
    if(index == 0) return (arr[0] == k);

    if(dp[index][k] != -1) return dp[index][k];
    
    bool notTake = f(index-1, k, arr, dp);
    bool take = false;
    if(arr[index] <= k) {
        take = f(index-1, k-arr[index], arr, dp);
    }

    return dp[index][k] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));

    for(int i = 0 ; i < n ; i++) dp[i][0] = true; 
    dp[0][arr[0]] = true;

    for(int ind=1 ; ind<n ; ind++){
        for(int target=1 ; target<=k ; target++){
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if(arr[ind] <= target) {
                take = dp[ind-1][target-arr[ind]];
            }

            dp[ind][target] = take | notTake;
        }
    }

    return dp[n-1][k];
}
