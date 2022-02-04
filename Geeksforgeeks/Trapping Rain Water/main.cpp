// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        // in left and right arrays we are calculating the maximum heights of the pillars, from left to right and right to left traversal
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int max = arr[0];

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }

            left[i] = max;
        }

        max = arr[n - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > max)
                max = arr[i];

            right[i] = max;
        }

        long long waterTrapped = 0;
        // the water stored on the block will be the difference between the (minimum of the left max and right max) and (the height of the block we're on)
        for (int i = 1; i < n - 1; i++)
        {
            int minimum = min(left[i], right[i]);

            waterTrapped += minimum - arr[i];
        }

        return waterTrapped;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends