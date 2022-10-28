//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> v)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int j=0 ; j<m ; j++){
            for(int i=0 ; i<n ; i++){
                if(j == 0){
                    dp[i][j] = v[i][j];
                } else {
                    //from upward
                    if(i-1 >= 0 && j-1 >= 0){
                        dp[i][j] = max(dp[i-1][j-1] + v[i][j] , dp[i][j]);
                    }
                    
                    //from behind
                    if(j - 1 >= 0){
                        dp[i][j] = max(dp[i][j-1] + v[i][j], dp[i][j]);
                    }
                    
                    //from below
                    if(i + 1 < n && j - 1 >= 0){
                        dp[i][j] = max(dp[i+1][j-1] + v[i][j], dp[i][j]);
                    }
                }
            }
        }
        
        int res = INT_MIN;
        
        for(int i=0 ; i<n ; i++){
            res = max(dp[i][m-1], res);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
