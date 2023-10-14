//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class DisjointSet 
{
    private:
    vector<int> parent, size;
    
    public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }
    
    int findUParent(int u) {
        if(parent[u] == u) return u;
        
        return parent[u] = findUParent(parent[u]);
    }
    
    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        
        if(pu == pv) return;
        
        if(size[pu] < size[pv]) {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        } else {
            parent[pv] = parent[pu];
            size[pu] += size[pv];        
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> adjMat;
        for(int i = 0 ; i < V ; i++){
            for(auto it : adj[i]) {
                adjMat.push_back({it[1], {i, it[0]}});
            }
        }
        
        sort(adjMat.begin(), adjMat.end());
        
        DisjointSet ds = DisjointSet(V);
        int weight = 0;
        
        for(auto it : adjMat) {
            int u = it.second.first;
            int v = it.second.second;
            int d = it.first;
            
            if(ds.findUParent(u) == ds.findUParent(v)) continue;
            
            weight += d;
            ds.unionBySize(u, v);
        }
        
        return weight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
