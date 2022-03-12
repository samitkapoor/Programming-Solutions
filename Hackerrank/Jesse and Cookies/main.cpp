#include <bits/stdc++.h>

using namespace std;

int main()
{
    int counter = 0;
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> a;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push(t);
    }

    while (a.top() < k)
    {
        if (a.size() < 2)
        {
            cout << -1 << endl;
            return 0;
        }

        int x = a.top();
        a.pop();
        int y = a.top();
        a.pop();
        a.push(x + 2 * y);
        counter++;
    }

    cout << counter << endl;

    return 0;
}