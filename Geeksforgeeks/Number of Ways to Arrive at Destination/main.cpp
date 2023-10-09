//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(int i = 0 ; i < roads.size() ; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distances(n, INT_MAX);
        vector<int> ways(n, 0);
        distances[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        int mod = (int)(1e9 + 7);
        
        while(!pq.empty()) {
            int distance = pq.top().first;
            int city = pq.top().second;
            pq.pop();
            
            for(auto it: adj[city]) {
                int destination = it.first;
                int roadDistance = it.second;
                
                if(roadDistance + distance < distances[destination]) {
                    distances[destination] = (roadDistance + distance)%mod;
                    ways[destination] = ways[city];
                    pq.push({distances[destination], destination});
                } else if(roadDistance + distance == distances[destination]) {
                    ways[destination] = (ways[destination] + ways[city]) % mod;
                }
            }
        }
        
        return ways[n-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
