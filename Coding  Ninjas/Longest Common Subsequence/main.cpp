#include <bits/stdc++.h> 

int lcs(int ind1, int ind2, string& str1, string& str2, vector<vector<int>> &dp) { //recursion with memoization
  if(ind1 < 0 || ind2 < 0) return 0;

  if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

  if(str1[ind1] == str2[ind2]) {
    return dp[ind1][ind2] = 1 + lcs(ind1-1, ind2-1, str1, str2, dp);
  }
  else{
    return dp[ind1][ind2] = 0 + max(lcs(ind1-1, ind2, str1, str2, dp), lcs(ind1, ind2-1, str1, str2, dp));
  }
}

int getLengthOfLCS(string & str1, string & str2) { //tabulation method
  int n1 = str1.length();
  int n2 = str2.length();

  vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

  for(int i = 1 ; i <= n1 ; i++){
    for(int j = 1 ; j <= n2 ; j++){
      if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
    }
  }

  return dp[n1][n2];
}
