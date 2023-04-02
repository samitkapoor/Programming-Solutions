//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(int i, int j, string x, string y, vector<vector<int>>& dp) { //recursion with memoization
        
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(x[i] == y[j]) {
            return dp[i][j] = 1 + lcs(i-1, j-1, x, y, dp);
        } else {
            return dp[i][j] = 0 + max(lcs(i-1, j, x, y, dp), lcs(i, j-1, x, y, dp));
        }
        
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n) //tabulation method
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 1 ; i <= m ; i++){ //calculating the length of the longest common subsequence
            for(int j = 0 ; j <= n ; j++){ 
                if(X[i-1] == Y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return m + n - dp[m][n];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
