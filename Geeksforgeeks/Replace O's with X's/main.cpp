//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void span(int r, int c, int n, int m, vector<vector<char>>& mat, vector<vector<char>>& ans) {
        if(r < 0 || c < 0 || r >= n || c >= m || mat[r][c] == 'X' || ans[r][c] == 'O') {
            return;
        }
        
        mat[r][c] = 'X';
        ans[r][c] = 'O';
        
        span(r-1, c, n, m, mat, ans);
        span(r+1, c, n, m, mat, ans);
        span(r, c-1, n, m, mat, ans);
        span(r, c+1, n, m, mat, ans);
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(mat.size(), vector<char>(mat[0].size(), 'X'));
        
        for(int i = 0 ; i < n ; i++){
            if(mat[i][0] == 'O') {
                span(i, 0, n, m, mat, ans);
            }
            
            if(mat[i][m-1] == 'O') {
                span(i, m-1, n, m, mat, ans);
            }
        }
        
        for(int j = 0 ; j < m ; j++){
            if(mat[0][j] == 'O') {
                span(0, j, n, m, mat, ans);
            }
            
            if(mat[n-1][j] == 'O') {
                span(n-1, j, n, m, mat, ans);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
