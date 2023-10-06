//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        efforts[0][0] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        
        vector<int> dr{1, -1, 0, 0};
        vector<int> dc{0, 0, 1, -1};
        
        while(!q.empty()) {
            int eff = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int drow = row + dr[i];
                int dcol = col + dc[i];
                
                if(drow < 0 || dcol < 0 || drow >= m || dcol >= n) continue;
                
                if(efforts[drow][dcol] > max(eff, abs(heights[drow][dcol]-heights[row][col]))) {
                    efforts[drow][dcol] = max(eff, abs(heights[drow][dcol]-heights[row][col]));
                    q.push({efforts[drow][dcol], {drow, dcol}});
                }
            }
        }
        
        
        return efforts[m-1][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
