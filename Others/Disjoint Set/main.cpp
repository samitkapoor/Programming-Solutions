#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
private:
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
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
};

int main()
{
    DisjointSet ds = DisjointSet(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findUParent(3) == ds.findUParent(7))
        cout << "Same" << endl;
    else
        cout << "NotSame" << endl;

    ds.unionByRank(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7))
        cout << "Same" << endl;
    else
        cout << "NotSame" << endl;

    return 0;
}