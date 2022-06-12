#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int x = v[0] + v[n - 1];

        for (int i = n - 1; i > 0; i--)
        {
            int y = v[i] + v[i - 1];

            x = max(y, x);
        }
        
        cout<<x<<endl;
    }
    return 0;
}
