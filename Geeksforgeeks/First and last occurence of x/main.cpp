// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// we apply a little modified binary search to tackle this question
vector<int> find(int arr[], int n, int x)
{
    int l = 0, r = n;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        // we need to check two conditions in order to find the left most key element in the array
        // we check if the current element is x and the previous one should not be x
        // if the condition is true then we have found the left most key element
        if (arr[m] == x && (m == 0 || arr[m - 1] != arr[m]))
        {
            vector<int> result(2, 0);
            result[0] = m;
            // using this loop we find the right most position of the key element
            while (arr[m++] == x)
                ;
            result[1] = m - 2;
            return result;
        }
        else if (arr[m] >= x)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    vector<int> result{-1, -1};
    return result;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends