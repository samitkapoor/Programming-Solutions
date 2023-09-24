//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int, int>>& temp, int basei, int basej) {
            visited[i][j] = 1;
            vector<int> drow{-1, 0, 1, 0};
            vector<int> dcol{0, -1, 0, 1};
            
            for(int k = 0 ; k < 4 ; k++){
                int nrow = i + drow[k];
                int ncol = j + dcol[k];
                
                if(nrow < 0 || ncol < 0 || nrow >= m || ncol >= n || visited[nrow][ncol] == 1 || grid[nrow][ncol] == 0) continue;
                
                temp.push_back({nrow-basei, ncol-basej});
                
                dfs(nrow, ncol, m, n, grid, visited, temp, basei, basej);
            }
        }
        
    public:
        int countDistinctIslands(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> visited(m, vector<int>(n, 0));
            
            set<vector<pair<int,int>>> res;
            
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(visited[i][j] != 1 && grid[i][j] == 1) {
                        vector<pair<int, int>> temp;
                        temp.push_back({i-i, j-j});
                        dfs(i, j, m, n, grid, visited, temp, i, j);
                        
                        res.insert(temp);
                    }
                }
            }
            
            return res.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
