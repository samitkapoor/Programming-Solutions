//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegrees(V, 0);
        
        for(int i = 0 ; i < V ; i++){
            for(auto node: adj[i]) {
                inDegrees[node]++;
            }
        }
        
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(inDegrees[i] == 0) {
                q.push(i);
            }
        }
        
        if(q.empty()) return true;
        
        vector<int> topoSort;
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            
            for(auto node: adj[i]) {
                inDegrees[node]--;
                if(inDegrees[node] == 0) q.push(node);
                if(inDegrees[node] < 0) return true;
            }
            
            topoSort.push_back(i);
        }
        
        if(topoSort.size() != V) return true;
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
