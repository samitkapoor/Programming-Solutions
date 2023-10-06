//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        distances[source.first][source.second] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, source});
        
        vector<int> dr{1, -1, 0, 0};
        vector<int> dc{0, 0, 1, -1};
        
        while(!q.empty()) {
            int dis = q.front().first;
            pair<int, int> node = q.front().second;
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int drow = node.first + dr[i];
                int dcol = node.second + dc[i];
                
                if(drow < 0 || dcol < 0 || drow >= grid.size() || dcol >= grid[0].size() || grid[drow][dcol] != 1) {
                    continue;
                }
                
                if(distances[drow][dcol] > dis + 1) {
                    distances[drow][dcol] = dis + 1;
                    q.push({dis+1, {drow, dcol}});
                }
            }
        }
        
        return distances[destination.first][destination.second] == INT_MAX? -1 : distances[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
