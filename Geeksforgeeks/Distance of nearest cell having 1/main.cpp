//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<int>> nearestOne(grid.size(), vector<int>(grid[0].size(), 0));
	    queue<pair<pair<int, int>,int>> q;
	    
	    for(int i = 0 ; i < grid.size() ; i++){
	        for(int j = 0 ; j < grid[i].size() ; j++){
	            if(grid[i][j] == 1) {
	                q.push({{i, j}, 0});
	            }
	        }
	    }
	    
	    while(!q.empty()) {
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        
	        nearestOne[i][j] = d;
	        
	        if(i > 0 && grid[i-1][j] == 0) {
	            grid[i-1][j] = 1;
	            q.push({{i-1, j}, d+1});
	        }
	        if(j > 0 && grid[i][j-1] == 0) {
	            grid[i][j-1] = 1;
	            q.push({{i, j-1}, d+1});
	        }
	        if(i < grid.size()-1 && grid[i+1][j] == 0) {
	            grid[i+1][j] = 1;
	            q.push({{i+1, j}, d+1});
	        }
	        if(j < grid[0].size()-1 && grid[i][j+1] == 0) {
	            grid[i][j+1] = 1;
	            q.push({{i, j+1}, d+1});
	        }
	    }
	    
	    return nearestOne;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
