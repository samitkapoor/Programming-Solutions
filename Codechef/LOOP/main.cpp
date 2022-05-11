#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, m;
        cin >> a >> b >> m;
        int c, ac;
        if (a > b)
        {
            ac = a - b;
            c = m - a + b;
        }
        else
        {
            c = b - a;
            ac = a + m - b;
        }

        cout << min(c, ac) << endl;
    }

    return 0;
}