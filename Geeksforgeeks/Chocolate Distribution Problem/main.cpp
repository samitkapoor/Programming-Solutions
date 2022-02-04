// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code
        sort(a.begin(), a.end());
        long long result = 2147483648;
        for (int i = 0; i + m - 1 < n; i++)
        {
            // checking consecutive subarrays of length m and storing the minimum difference
            result = min(result, a[i + m - 1] - a[i]);
        }

        return result;
    }
};

// { Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
} // } Driver Code Ends