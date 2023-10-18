//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }
    
    int findUParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findUParent(parent[n]);
    }
    
    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        
        if(pu == pv) return;
        
        if(size[pu] < size[pv]) {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        } else {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};

class Solution {
  private:
    bool isValid(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        
        DisjointSet ds = DisjointSet(n * n);
        
        vector<int> dx{-1, 1, 0, 0};
        vector<int> dy{0, 0, -1, 1};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) continue;
                
                for(int x = 0 ; x < 4 ; x++){
                    int newR = i + dx[x];
                    int newC = j + dy[x];
                    
                    if(isValid(newR, newC, n) && grid[newR][newC] == 1) {
                        ds.unionBySize(newR * n + newC, i * n + j);
                    }
                }
            }
        }
        
        int mx = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) continue;
                set<int> components;
                for(int x = 0 ; x < 4 ; x++){
                    int newR = i + dx[x];
                    int newC = j + dy[x];
                    
                    if(isValid(newR, newC, n)) {
                        if(grid[newR][newC] == 1) {
                            components.insert(ds.findUParent(newR * n + newC));
                        }
                    }
                }
                
                int size = 0;
                for(auto it: components) {
                    size += ds.size[it];
                }
                mx = max(mx, size + 1);
            }
        }
        
        for(int cell = 0 ; cell < n * n ; cell++){
            mx = max(mx, ds.size[ds.findUParent(cell)]);
        }
        
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends
