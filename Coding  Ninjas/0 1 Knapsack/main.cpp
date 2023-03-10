#include <bits/stdc++.h> 

int f(vector<int> weight, vector<int> value, int n, int totalWeight, int index, vector<vector<int>> dp) { //recursion with memiozation approach
	if(index == 0) {
		if(weight[0] <= totalWeight) return value[0];
		else return 0;
	}

	if(dp[index][totalWeight] != -1) return dp[index][totalWeight];

	int notTake = 0 + f(weight, value, n, totalWeight, index-1, dp);
	int take = 0;
	if(weight[index] <= totalWeight)
		take = value[index] + f(weight, value, n, totalWeight-weight[index], index-1, dp);

	return dp[index][totalWeight] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) //dp tabulation
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

	for (int w = weight[0] ; w <= maxWeight ; w++) {
		dp[0][w] = value[0];
	}

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j <= maxWeight ; j++){
			int notTake = 0 + dp[i-1][j];
			int take = 0;
			if(weight[i] <= j)
				take = value[i] + dp[i-1][j-weight[i]];

			dp[i][j] = max(notTake, take);
		}
	}

	return dp[n-1][maxWeight];
}
