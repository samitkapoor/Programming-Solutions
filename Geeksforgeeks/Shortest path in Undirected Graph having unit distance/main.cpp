//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfs(int i, vector<int>&visited, vector<int> adj[], vector<int>&distances) {
        visited[i] = 1;
        
        for(auto node : adj[i]) {
            if(distances[i] + 1 < distances[node]) {
                distances[node] = distances[i]+1;
                dfs(node, visited, adj, distances);
            }
        }
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i = 0 ; i < M ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(N, 0);
        vector<int> distances(N, INT_MAX);
        distances[src] = 0;
        dfs(src, visited, adj, distances);
        
        for(int i = 0 ; i < N ; i++){
            if(distances[i] == INT_MAX) distances[i] = -1;
        }
        
        return distances;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
