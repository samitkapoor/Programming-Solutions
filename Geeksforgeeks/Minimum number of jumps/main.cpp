// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n, -1);

        // because we wont be taking any jumps from the last element so dp[n-1] = 0
        dp[n - 1] = 0;

        // we iterate backwards
        for (int i = n - 2; i >= 0; i--)
        {
            // number of steps we can take is arr[i]
            int steps = arr[i];
            int min = 2147483647;
            // i + j < n is necessary so that we dont step out of bounds
            for (int j = 1; j <= steps && i + j < n; j++)
            {
                // if dp[i+1] == -1 then that means there is no path from there
                // and as we are looking for minimum jumps we check dp[i+j] < min
                if (dp[i + j] != -1 && dp[i + j] < min)
                {
                    min = dp[i + j];
                }
            }

            // if min == 2147483647 then that means there is no path to n-1 from i
            if (min != 2147483647)
            {
                // plus 1 because we will be taking the jump from dp[i]
                dp[i] = min + 1;
            }
        }

        return dp[0];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends