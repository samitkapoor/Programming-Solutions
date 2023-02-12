//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPossible(vector<vector<int>> board, int row, int col, int n) {
        int i = row;
        int j = col;
        
        while(i >= 0 && j >= 0) {
            if(board[i--][j--] == 1) return false;
        }
        
        i = row;
        j = col;
        
        while(i >= 0) {
            if(board[i--][j] == 1) return false;
        }
        
        i = row;
        j = col;
        
        while(i >= 0 && j < n) {
            if(board[i--][j++] == 1) return false;
        }
        
        return true;
    }

    void solve(int n, vector<vector<int>>& result, vector<int> curr, vector<vector<int>> board, int row) {
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(isPossible(board, row, i, n)) {
                board[row][i] = 1;
                curr.push_back(i+1);
                solve(n, result, curr,board, row+1);
                board[row][i] = 0;
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(n, result, curr, board, 0);
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
