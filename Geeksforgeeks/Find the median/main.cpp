// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
public:
    int find_median(vector<int> V)
    {
        // Code here.
        sort(V.begin(), V.end());
        if (V.size() % 2 == 0)
        {
            int x = V[V.size() / 2];
            int y = V[(V.size() / 2) - 1];

            return (x + y) / 2;
        }
        return V[V.size() / 2];
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution ob;
        int ans = ob.find_median(v);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends