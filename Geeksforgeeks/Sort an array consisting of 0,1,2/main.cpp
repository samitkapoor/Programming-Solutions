// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {
        int cz = 0, co = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                cz++;
            else if (a[i] == 1)
                co++;
        }
        int i = 0;

        while (i < cz)
            a[i++] = 0;

        while (i < (co + cz))
            a[i++] = 1;

        while (i < n)
            a[i++] = 2;
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
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends