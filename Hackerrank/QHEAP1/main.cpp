#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::set<int> pq;
    int t;
    cin >> t;

    while (t--)
    {

        int a, b;
        cin >> a;

        if (a != 3)
            cin >> b;
        else
            cout << *pq.begin() << endl;

        if (a == 1)
            pq.insert(b);

        if (a == 2)
        {
            auto it = pq.find(b);
            pq.erase(it);
        }
    }

    return 0;
}
