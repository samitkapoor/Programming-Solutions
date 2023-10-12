//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
        vector<vector<int>> disMat(n, vector<int>(n, 1e9));
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int dis = edge[2];
            
            disMat[v][u] = disMat[u][v] = dis;
        }
        
        for(int i = 0 ; i < n ; i++){
            disMat[i][i] = 0;
        }
        
        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    disMat[i][j] = min(disMat[i][j], disMat[i][via] + disMat[via][j]);
                }
            }
        }
        
        int minDis = 1e9;
        int maxVertice = n-1;
        
        for(int i = 0 ; i < n ; i++){
            int counter = 0;
            for(int j = 0 ; j < n ; j++){
                if(disMat[i][j] <= distanceThreshold) counter++;
            }
            
            if(counter < minDis) {
                minDis = counter;
                maxVertice = i;
            } else if(counter == minDis) {
                maxVertice = i;
            }
        }
        
        return maxVertice;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
