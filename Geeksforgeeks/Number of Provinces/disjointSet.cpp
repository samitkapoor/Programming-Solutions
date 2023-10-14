//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet {
    private:
    vector<int> parent, size;
    public:
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int n) {
        if(parent[n] == n) return n;
        
        return parent[n] = findUltimateParent(parent[n]);
    }
    
    void unionBySize(int u, int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
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

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds = DisjointSet(V);
        
        int counter = 0;
        
        for(int i = 0 ; i < adj.size() ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                if(adj[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }
        
        for(int i = 0 ; i < V ; i++){
            if(ds.findUltimateParent(i) == i) {
                counter++;
            }
        }
        
        return counter;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
