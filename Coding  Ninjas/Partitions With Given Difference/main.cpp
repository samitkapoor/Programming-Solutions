#include <bits/stdc++.h> 

int mod = (int)(1e9 + 7);

int countSubsets(vector<int> &nums, int tar) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(tar+1, 0));

    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 1;
    }
    for (int i = 1; i <= tar; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1 ; i < n + 1 ; i++){
        for(int j = 0 ; j < tar + 1 ; j++){
            if(nums[i-1] <= j) {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-nums[i-1]])%mod;
            } else {
                dp[i][j] = dp[i-1][j]%mod;
            }
        }
    }

    return dp[n][tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(int i : arr) {
        totalSum += i;
    }

    if(totalSum-d < 0 || (totalSum-d) % 2 != 0) return 0;
    return countSubsets(arr, (totalSum-d)/2);
}


