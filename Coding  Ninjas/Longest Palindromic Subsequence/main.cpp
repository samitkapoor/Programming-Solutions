#include <bits/stdc++.h> 

int getLengthOfLCS(string &str1, string &str2) { //tabulation method
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


int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(), t.end());

    return getLengthOfLCS(s, t);
}
