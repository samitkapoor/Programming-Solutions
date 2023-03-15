#include <bits/stdc++.h> 

int f(int ind, int weightLeft, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) { //ecursive approach with memoization
    if(ind == 0) {
        if(weight[0] <= weightLeft)
            return (weightLeft/weight[0])*profit[0];
        else return 0;
    }

    if(dp[ind][weightLeft] != -1) return dp[ind][weightLeft];

    int notTake = 0 + f(ind-1, weightLeft, profit, weight, dp);
    int take = -1e9;
    if(weight[ind]<= weightLeft){ 
        take = profit[ind] + f(ind, weightLeft-weight[ind], profit, weight, dp);
    }

    return dp[ind][weightLeft] = max(notTake, take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) //reduced space complexity in the tabulation method
{
    vector<int> prev(w+1, 0);

    for(int W = 0 ; W <= w ; W++){
        if(weight[0] <= W) prev[W] = (W/weight[0])*profit[0];
    }

    for(int ind = 1 ; ind < n ; ind++){
        vector<int> curr(w+1, 0);
        for(int weightLeft = 0 ; weightLeft <= w ; weightLeft++){
            int notTake = 0 + prev[weightLeft];
            int take = -1e9;
            if(weight[ind]<= weightLeft){ 
                take = profit[ind] + curr[weightLeft-weight[ind]];
            }

            curr[weightLeft] = max(notTake, take);
        }

        prev = curr;
    }


    return prev[w];
}
