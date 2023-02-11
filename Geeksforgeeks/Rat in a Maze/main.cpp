//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<string>& result, vector<vector<int>> m, int n, int i, int j, string currPath, vector<vector<int>> visited) {
        if(m[i][j] == 0){
            return;
        }
        
        if(i == n-1 && j == n-1){
            result.push_back(currPath);
            return;
        }
        
        if(i + 1 < n && visited[i+1][j] == 0 && m[i+1][j] == 1){
            visited[i+1][j] = 1;
            solve(result, m, n, i+1, j, currPath + "D", visited);
            visited[i+1][j] = 0;
        }
        if(j + 1 < n && visited[i][j+1] == 0 && m[i][j+1] == 1){
            visited[i][j+1] = 1;
            solve(result, m, n, i, j+1, currPath + "R", visited);
            visited[i][j+1] = 0;
        }
        if(i - 1 >= 0 && visited[i-1][j] == 0 && m[i-1][j] == 1){
            visited[i-1][j] = 1;
            solve(result, m, n, i-1, j, currPath + "U", visited);
            visited[i-1][j] = 0;
        }
        if(j - 1 >= 0 && visited[i][j-1] == 0 && m[i][j-1] == 1){
            visited[i][j-1] = 1;
            solve(result, m, n, i, j-1, currPath + "L", visited);
            visited[i][j-1] = 0;
        }
        
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return {"-1"};
        }
        
        visited[0][0] = 1;
        
        solve(result, m, n, 0, 0, "", visited);
        
        return result;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
