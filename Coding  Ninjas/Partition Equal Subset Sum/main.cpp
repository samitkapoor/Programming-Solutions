bool findSubset(int n, int target, vector<int>& arr) {
	vector<vector<bool>> dp(n, vector<bool>(target+1, false));

	for(int i = 0 ; i < n ; i++){
		dp[i][0] = true;
	}
	dp[0][arr[0]] = true;

	for(int i = 1 ; i < n ; i++){
		for(int j = 1 ; j <= target ; j++){
			bool notTake = dp[i-1][j];
			bool take = false;
			if(j >= arr[i]) take = dp[i-1][j-arr[i]];

			dp[i][j] = take | notTake;
		}
	}

	return dp[n-1][target];
}

bool canPartition(vector<int> &arr, int n)
{
	int totalSum = 0;
	for(int i=0 ; i<n ; i++){
		totalSum += arr[i];
	}

	if(totalSum % 2 != 0) {
		return false;
	}

	int targetSum = totalSum / 2;

	return findSubset(n, targetSum, arr);
}
