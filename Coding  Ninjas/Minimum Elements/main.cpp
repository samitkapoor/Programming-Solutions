#include <bits/stdc++.h> 

int f(int index, int x, vector<int> &nums, vector<vector<int>>& dp) {
    if(index == 0) {
        if(x % nums[0] == 0) return x/nums[0];
        else return INT_MAX;
    }

    if(dp[index][x] != -1) return dp[index][x];

    int notTake = f(index-1, x, nums, dp);
    int take = 1e9;
    if(nums[index] <= x){
        take = 1 + f(index, x-nums[index], nums, dp);
    }

    return dp[index][x] = min(take, notTake);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, INT_MAX));
    
    for(int i=0 ; i<=x ; i++){
        if(i % num[0]==0) dp[0][i] = i/num[0];
        else dp[0][i] = 1e9;
    }

    for(int index = 1 ; index < n ; index++){
        for(int j = 0 ; j <= x ; j++){
            int notTake = dp[index-1][j];
            int take = 1e9;
            if(num[index] <= j){
                take = 1 + dp[index][j-num[index]];
            }

            dp[index][j] = min(take, notTake);
        }
    }

    int ans = dp[n-1][x];

    if(ans >= 1e9) return -1;
    else return ans;
}
