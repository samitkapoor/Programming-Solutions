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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == i + 1 + cnt)
            {
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}