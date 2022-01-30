// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(int *arr, int n)
    {
        // code here
        vector<int> result(2);
        vector<int> hashMap(n, 1);

        for (int i = 0; i < n; i++)
        {
            if (hashMap[arr[i] - 1] == 0)
            {
                result[0] = arr[i];
            }
            else
            {
                hashMap[arr[i] - 1] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (hashMap[i] == 1)
            {
                result[1] = i + 1;
                break;
            }
        }

        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends