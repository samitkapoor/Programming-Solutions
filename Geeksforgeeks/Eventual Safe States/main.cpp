//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i, vector<int>&visited, vector<int>&pathVisited, vector<int> adj[]) {
        visited[i] = 1;
        pathVisited[i] = 1;
        
        for(auto node: adj[i]) {
            if(!visited[node]) {
                if(dfs(node, visited, pathVisited, adj)) {
                    return true;
                }
            }
            else if(pathVisited[node]) return true;
        }
        
        pathVisited[i] = 0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> safeNodes;
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]) {
                dfs(i, visited, pathVisited, adj);
            }
        }
        
        for(int i = 0 ; i < V ; i++){
            if(pathVisited[i] == 0) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
