// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        // code here
        // we create a hashmap and only insert the value that occurs in the array once
        unordered_map<int, int> hashMap;

        for (int i = 0; i < n; i++)
        {
            // inserting only those items that have not appeared before
            if (hashMap.find(a[i]) == hashMap.end())
            {
                hashMap.insert(make_pair(a[i], 1));
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (hashMap.find(b[i]) == hashMap.end())
            {
                hashMap.insert(make_pair(b[i], 1));
            }
        }

        // returning the number of elements in the hashMap
        return hashMap.size();
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
} // } Driver Code Ends