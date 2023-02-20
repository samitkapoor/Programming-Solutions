#include <bits/stdc++.h> 

int solve(vector<int> nums, vector<vector<int>>& dp) {
    for(int i = 1 ; i < dp.size() ; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + nums[i];
    }    

    return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    if(n == 1) return nums[0];

    dp[0][0] = 0;
    dp[0][1] = nums[0];

    return solve(nums, dp);
}
