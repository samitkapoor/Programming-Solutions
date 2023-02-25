#include <bits/stdc++.h> 

void solve(vector<vector<int>>& triangle, int n, vector<int> &dp) {
	for(int i = 1 ; i<n ; i++){
		vector<int> curr(n, 0);
        for (int j = 0; j < triangle[i].size(); j++) {
			if(j==0) {
				curr[j] = triangle[i][j] + dp[j];
            } else if (j == triangle[i].size() - 1) {
                curr[j] = triangle[i][j] + dp[j-1];
			} else {
            	curr[j] = min(triangle[i][j] + dp[j], triangle[i][j] + dp[j-1]);
            }
        }

		dp = curr;
    }
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> dp(n, 0);

	dp[0] = triangle[0][0];

	if(n==1) return dp[0];

	solve(triangle, n, dp);

	int mini = INT_MAX;
	for(int i : dp) {
		mini = min(mini, i);
	}

	return mini;
}
