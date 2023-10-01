//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> result;
        
        vector<int> temp[V];
        for(int i = 0 ; i <V ; i++){
            for(int node: adj[i]) {
                temp[node].push_back(i);
            }
        }
        
        adj = temp;
        
        vector<int> outDegrees(V, 0);
        for(int i = 0 ; i <V ; i++){
            for(int node: adj[i]) {
                outDegrees[node]++;
            }
        }
        
        queue<int> zeroDegree;
        for(int i = 0 ; i < V ; i++){
            if(outDegrees[i] == 0) {
                zeroDegree.push(i);
            }
        }
        
        while(!zeroDegree.empty()) {
            int currNode = zeroDegree.front();
            zeroDegree.pop();
            
            for(auto node: adj[currNode]) {
                outDegrees[node]--;
                if(outDegrees[node] == 0) zeroDegree.push(node);
            }
            
            result.push_back(currNode);
        }   
        
        sort(result.begin(), result.end());
        
        return result;
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
