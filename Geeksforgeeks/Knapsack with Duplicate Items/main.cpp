//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int totalBalls, int runs[], int balls[])
    {
        vector<int> dp(totalBalls+1, 0);
        
        for(int i=0 ; i<dp.size() ; i++){
            for(int j=0 ; j<n ; j++){
                if(balls[j] <= i){
                    dp[i] = max(dp[i], dp[i - balls[j]] + runs[j]);
                }
            }
        }
        
        return dp[totalBalls];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
