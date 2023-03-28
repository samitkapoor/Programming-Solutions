#include <bits/stdc++.h> 

int f(string s, string t) {
    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int minInsertion(string &str)
{
    string t = str;
    reverse(t.begin(), t.end());
    return str.length()-f(str, t);
}
