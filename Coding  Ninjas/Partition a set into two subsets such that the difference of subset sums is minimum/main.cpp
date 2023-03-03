#include <bits/stdc++.h> 

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
	for(int i = 0 ; i < arr.size() ; i++) totalSum += arr[i];

	vector<vector<bool>> dp(n, vector<bool>(totalSum+1, false));

	for(int i = 0 ; i < n ; i++){
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;

	for(int i = 1 ; i < n ; i++){
		for(int j = 1 ; j <= totalSum ; j++){
			bool notTake = dp[i-1][j];
			bool take = false;

			if(j >= arr[i]) {
				take = dp[i-1][j - arr[i]];
			}

			dp[i][j] = take | notTake;
		}
	}

	int mini = INT_MAX;

	for(int i = 0 ; i <= totalSum/2 ; i++){
		if(dp[n-1][i] == true) {
			mini = min(mini, abs((totalSum -  i) - i));
		}
	}

	return mini;
}
