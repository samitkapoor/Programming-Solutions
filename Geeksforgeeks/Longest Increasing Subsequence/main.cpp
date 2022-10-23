//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int dp[n] = {0};
       
       dp[0] = 1;
       
       for(int i=1 ; i<n ; i++){
           int m = 0;
           for(int j=0 ; j<i ; j++){
               if(a[j] < a[i]){
                 m = max(m, dp[j] + 1);
               }
               else{
                   m = max(m, 1);
               }
           }
           
           dp[i] = m;
       }
       
       int temp = -1;
       for(int i=0 ; i<n ; i++){
           temp = max(temp, dp[i]);
       }
       
       return temp;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
