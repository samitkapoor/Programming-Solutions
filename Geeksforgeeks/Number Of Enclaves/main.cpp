//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void removeLand(int i, int j, vector<vector<int>>& path) {
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if(r < 0 || c < 0 || r >= path.size() || c >= path[0].size() || path[r][c] != 1) {
                continue;
            }
            
            path[r][c] = 0;
            
            q.push({r+1, c});
            q.push({r-1, c});
            q.push({r, c+1});
            q.push({r, c-1});
        }
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        vector<vector<int>> path = grid;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0 ; i < m ; i++){
            if(path[i][0] == 1) {
                removeLand(i, 0, path);
            }
            
            if(path[i][n-1] == 1) {
                removeLand(i, n-1, path);
            }
        }
        
        for(int j = 0 ; j < n ; j++){
            if(path[0][j] == 1) {
                removeLand(0, j, path);
            }
            
            if(path[m-1][j] == 1) {
                removeLand(m-1, j, path);
            }
        }
        
        int countLand = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(path[i][j] == 1) countLand++;
            }
        }
        
        return countLand;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
