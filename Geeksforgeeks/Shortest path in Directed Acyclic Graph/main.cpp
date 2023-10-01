//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfs(int i, stack<int>&stk, vector<int>&visited, vector<pair<int, int>> adj[]) {
        visited[i] = 1;
        
        for(auto p : adj[i]) {
            if(!visited[p.first]) {
                dfs(p.first, stk, visited, adj);
            }
        }
        
        stk.push(i);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //form the adjacency matrix
        vector<pair<int, int>> adj[N];
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1]; 
            int d = edges[i][2];
            
            adj[u].push_back({v,d});
        }
        
        //form topo order
        stack<int> stk;
        vector<int> visited(N, 0);
        for(int i = 0 ; i < N ; i++){
            if(!visited[i]) {
                dfs(i, stk, visited, adj);
            }
        }
        
        //calculate relaxed distances
        vector<int> distances(N, 1e9);
        distances[0] = 0;
        while(!stk.empty()) {
            int curr = stk.top();
            stk.pop();
            
            for(auto p: adj[curr]) {
                int v = p.first;
                int d = p.second;
                
                if(distances[curr] + d < distances[v]) {
                    distances[v] = distances[curr] + d;
                }
            }
        }
        
        for(int i = 0 ; i < N ; i++){
            if(distances[i] == 1e9) distances[i] = -1;
        }
        
        return distances;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
