// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> m;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            // we check if the complement of the arr[i] is present in the map or not if it is present then that means
            // we have found a pair that lead up to k sum so we update the count variable
            if (m.find(k - arr[i]) != m.end())
            {
                count += m[k - arr[i]];
            }
            // in every iteration we add arr[i] key to the map to keep track of all the numbers that we have passed
            // also this is necessary for the upcoming iterations where we will be checking the complements
            m[arr[i]]++;
        }

        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
} // } Driver Code Ends