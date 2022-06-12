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

        int negs = 0;
        int poss = 0;

        for (int i = 0; i < n; i++)
        {
            if (v[i] == -1)
            {
                negs++;
            }
            else
            {
                poss++;
            }
        }

        if ((negs + poss) % 2 != 0)
            cout << -1 << endl;
        else
            cout << abs(poss - negs) / 2 << endl;
    }

    return 0;
}
