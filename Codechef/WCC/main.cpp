#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;

        int carlsen_cnt = 0;
        int chef_cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'C')
                carlsen_cnt++;
            else if (s[i] == 'N')
                chef_cnt++;
            else
                carlsen_cnt++, chef_cnt++;
        }

        if (carlsen_cnt > chef_cnt)
            cout << 60 * x << endl;
        else if (carlsen_cnt < chef_cnt)
            cout << 40 * x << endl;
        else
            cout << 55 * x << endl;
    }

    return 0;
}