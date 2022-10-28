//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum+1, false));
        dp[0][0] = true;
        for(int i=1 ; i<=arr.size() ; i++){
            for(int j=0 ; j<=sum ; j++){
                if(dp[i-1][j] == true){
                    dp[i][j] = true;
                }
                else if(j >= arr[i-1] && dp[i-1][j-arr[i-1]] == true){
                    dp[i][j] = true;
                }
            }
        }
        
        return dp[arr.size()][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
