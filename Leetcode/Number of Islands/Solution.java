class Solution {
    static void convertOnesToZeroes(char[][] grid, int i, int j){
        if(i<0 || i>=grid.length || j<0 || j>=grid[i].length || grid[i][j] == '0'){
            return;
        }
        
        grid[i][j] = '0';
        convertOnesToZeroes(grid, i+1, j);
        convertOnesToZeroes(grid, i-1, j);
        convertOnesToZeroes(grid, i, j+1);
        convertOnesToZeroes(grid, i, j-1);
    }
    
    public int numIslands(char[][] grid) {
        int counter = 0;
        
        for(int i=0 ; i<grid.length ; i++){
            for(int j=0 ; j<grid[i].length ; j++){
                if(grid[i][j] == '1'){
                    counter += 1;
                    convertOnesToZeroes(grid, i, j);
                }
            }
        }
        
        return counter;
    }
}