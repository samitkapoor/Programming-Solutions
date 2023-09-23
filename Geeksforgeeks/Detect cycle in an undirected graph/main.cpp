//This is the BFS approach
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int src, int V, vector<int> adj[], int vis[]) {
        queue<pair<int, int>> q;
        q.push(make_pair(src, -1));
        
        vis[src] = 1;
        
        while(!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            
            for(int i = 0 ; i < adj[curr.first].size() ; i++){
                if(vis[adj[curr.first][i]] == 1) {
                    if(adj[curr.first][i] != curr.second) return true;
                } else {
                    vis[adj[curr.first][i]] = 1;
                    q.push(make_pair(adj[curr.first][i], curr.first));
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]) {
                if(detectCycle(i, V, adj, vis)) return true;
            }
        }
        
        
        return false;
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
