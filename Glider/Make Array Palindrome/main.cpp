#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> array(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int i = 0, j = n - 1;
    int steps = 0;
    while (i < j)
    {
        if (array[i] == array[j])
            i++, j--;
        else if (array[i] > array[j])
        {
            array[i + 1] += array[i];
            i++;
            steps++;
        }
        else
        {
            array[j - 1] += array[j];
            j--;
            steps++;
        }
    }

    cout << steps << endl;

    return 0;
}