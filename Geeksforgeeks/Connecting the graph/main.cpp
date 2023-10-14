//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
            
            if(pu == pv) {
                return;
            }
            
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
    int Solve(int n, vector<vector<int>>& edges) {
        DisjointSet ds = DisjointSet(n);
        int extras = 0;
        
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            if(ds.findUltimateParent(u) == ds.findUltimateParent(v)) {
                extras += 1;
                continue;
            }
            
            ds.unionBySize(u, v);
        }
        
        int components = 0;
        for(int i = 0 ; i < n ; i++){
            if(ds.findUltimateParent(i) == i) components+=1;   
        }
        
        if(components - 1 <= extras) {
            return components-1;
        } 
        
        return -1;
    }
};































//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
