//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        vector<int> result(2);
        
        int curr_sum = arr[0];
        int start = 0;
        
        for(int i = 1 ; i <= n ; i++){
            while(curr_sum > s && start < i-1){
                curr_sum -= arr[start];
                start++;
            }
            
            if(curr_sum == s){
                result[0] = start+1;
                result[1] = i;
                return result;
            }
            
            if(i < n)
                curr_sum += arr[i];
        }
        
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
