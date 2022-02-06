#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int l, int r)
{

    int pivot = v[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (pivot > v[j])
        {
            i++;
            int temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = temp;

    return i + 1;
}

void quickSort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int p = partition(v, l, r);
        quickSort(v, l, p - 1);
        quickSort(v, p + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    quickSort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}