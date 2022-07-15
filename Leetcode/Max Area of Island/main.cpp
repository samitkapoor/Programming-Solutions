class Solution {
public:
    
    int expand(vector<vector<int>>& grid, int i, int j){
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        
        if(i >= 0 && j < n && i < m && j >= 0){
            
            if(grid[i][j] == 0){
                return 0;
            }
            
            grid[i][j] = 0;
            
            return 1 + expand(grid, i+1, j) + expand(grid, i, j+1) + expand(grid, i-1, j) + expand(grid, i, j-1);
        }
        
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int currArea = 0;
        
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    currArea = expand(grid, i, j);
                    
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;        
    }
};
