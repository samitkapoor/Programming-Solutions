class Solution {
    
    static int expand(int[][] grid, int i, int j){
        int m = grid.length;
        int n = grid[0].length;
        
        if(i >= 0 && j >= 0 && i < m && j < n){
            
            if(grid[i][j] == 0){
                return 0;
            }
            
            grid[i][j] = 0;
            
            return 1 + expand(grid, i+1, j) + expand(grid, i, j-1) + expand(grid, i, j+1) + expand(grid, i-1, j);           
        }
        
        return 0;
    }
    
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        int currArea = 0;
        
        int m = grid.length;
        int n = grid[0].length;
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    currArea = expand(grid, i, j);
                    
                    maxArea = Math.max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;        
    }
}
