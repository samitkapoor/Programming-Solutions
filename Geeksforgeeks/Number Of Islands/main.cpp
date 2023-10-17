//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    private:
    vector<int> parent, size;
    public:
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
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
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int k = operators.size();
        
        DisjointSet ds = DisjointSet(m*n);
        
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        
        vector<int> ans(k, 0);
        
        vector<int> dx{-1, 1, 0, 0};
        vector<int> dy{0, 0, 1, -1};
        for(int i = 0 ; i < k ; i++){
            int x = operators[i][0];
            int y = operators[i][1];
            if(matrix[x][y] == 1) {
                ans[i] = ans[i-1];
                continue;
            }
            
            int counter = ans[i-1] + 1;
            matrix[x][y] = 1;
            
            int fixNo = x * m + y;
            for(int j = 0 ; j < 4 ; j++){
                int drow = x + dx[j];
                int dcol = y + dy[j];
                
                if(drow < 0 || dcol < 0 || drow >= n || dcol >= m || matrix[drow][dcol] == 0) {
                    continue;
                } 
                
                int currNo = drow * m + dcol;
                
                if(ds.findUParent(fixNo) != ds.findUParent(currNo)) {
                    counter--;
                    ds.unionBySize(fixNo, currNo);
                } 
            }
            
            ans[i] = counter;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
