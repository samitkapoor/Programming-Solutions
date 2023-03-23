int splitRod(int ind, int n, vector<int> price, vector<vector<int>>& dp) { //recursion with memoization
	if(ind == 0) {
		return n * price[ind];
	}

	if(dp[ind][n] != -1) return dp[ind][n];

	int notTake = splitRod(ind-1, n, price, dp);
	int take = INT_MIN;
	if(ind+1 <= n) {
		take = price[ind] + splitRod(ind, n-ind-1, price, dp);
	}

	return dp[ind][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n) //tabulation
{
	vector<vector<int>> dp(n, vector<int>(n+1, 0));

	for(int i = 0 ; i <= n ; i++){
		dp[0][i] = i * price[0];
	}

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j <= n ; j++){
			int notTake = dp[i-1][j];
			int take = INT_MIN;
			if(i+1 <= j) {
				take = price[i] + dp[i][j-i-1];
			}

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n-1][n];
}
