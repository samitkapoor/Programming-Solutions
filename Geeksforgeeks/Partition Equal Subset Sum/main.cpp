//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0 ; i<N ; i++){
            sum += arr[i];
        }
        
        if ( sum % 2 != 0 ) {
            return 0;
        } else {
            sum = sum/2;
            vector<vector<bool>> dp(N+1, vector<bool>(sum+1));
            
            for(int i=0 ; i<dp.size() ; i++){
                for(int j=0 ; j<dp[0].size() ; j++){
                    if ( i == 0 && j == 0 ) {
                        dp[i][j] = true;
                    } else if ( i == 0 ) {
                        dp[i][j] = false;
                    } else if ( j == 0 ) {
                        dp[i][j] = true;
                    } else {
                        int score = arr[i-1];
                        
                        if ( dp[i-1][j] == true ) {
                            dp[i][j] = true;
                        }
                        
                        if ( score <= j ) {
                            if ( dp[i-1][j-score] == true ) {
                                dp[i][j] = true;
                            }
                        }
                    }
                }   
            }
            
            return dp[N][sum];
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
