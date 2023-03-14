#include<bits/stdc++.h>

long f(int ind, int val, int *denominations, vector<vector<long>> &dp) {
    if(ind == 0) {
        if(val % *(denominations + ind) == 0){
            return 1;
        } else {
            return 0;
        }
    }

    if(dp[ind][val] != -1) return dp[ind][val];

    long notTake = f(ind-1, val, denominations, dp);
    long take = 0;
    if(*(denominations + ind) <= val) {
        take = f(ind, val - *(denominations + ind), denominations, dp);
    }

    dp[ind][val] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value+1, 0);

    for(int val = 0 ; val <= value ; val++){
        prev[val] = (val % denominations[0] == 0);
    }

    for(int ind = 1 ; ind < n ; ind++){
        vector<long> curr(value+1, 0);
        for(int val = 0 ; val <= value ; val++){
            long notTake = prev[val];
            long take = 0;
            if(*(denominations + ind) <= val) {
                take = curr[val - *(denominations + ind)];
            }

            curr[val] = take + notTake;
        }
        prev = curr;
    }

    return prev[value];
}
