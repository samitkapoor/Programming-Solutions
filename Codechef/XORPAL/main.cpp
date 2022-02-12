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
        string s;
        cin >> s;

        if (n % 2 != 0)
        {
            cout << "YES" << endl;
            continue;
        }
        int cnt_zero = 0;
        int cnt_one = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                cnt_zero++;
            else
                cnt_one++;
        }

        if (cnt_zero % 2 != 0 && cnt_one % 2 != 0 && cnt_zero != cnt_one)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}