#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int n)
    {
        if (parent[n] == n)
            return n;

        return parent[n] = findUParent(parent[n]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        if (rank[pu] > rank[pv])
            parent[pv] = parent[pu];
        else if (rank[pu] < rank[pv])
            parent[pu] = parent[pv];
        else
        {
            parent[pu] = parent[pv];
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv])
        {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }
    }
};

int main()
{
    DisjointSet ds = DisjointSet(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUParent(3) == ds.findUParent(7))
        cout << "Same" << endl;
    else
        cout << "NotSame" << endl;

    ds.unionBySize(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7))
        cout << "Same" << endl;
    else
        cout << "NotSame" << endl;

    return 0;
}