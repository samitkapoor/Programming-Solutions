//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool traverse(int ind, int prev, int V, vector<int> adj[], vector<int>& vis) {
        if(vis[ind] == 1) return true;
        
        vis[ind] = 1;
        bool ans = false;
        for(auto vertice: adj[ind]) {
            if(vertice != prev && vertice != ind) {
                ans = ans | traverse(vertice, ind, V, adj, vis);
            }
        }
        
        return ans;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        bool ans = false;
        
        vector<int> vis(V, 0);
        
        for(int i = 0 ; i < V ; i++){
            if(vis[i] == 0)
                ans = ans | traverse(i, -1, V, adj, vis);
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
