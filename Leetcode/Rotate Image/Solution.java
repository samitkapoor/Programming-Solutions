class Solution {
    public void rotate(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        for(int i=0; i<rows ; i++){
            for(int j=0 ; j<i+1 ; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for(int i=0 ; i<cols/2 ; i++){
            for(int j=0 ; j<rows ; j++){
                int temp = matrix[j][i];
                matrix[j][i] = matrix[j][cols-i-1];
                matrix[j][cols-i-1] = temp;
            }
        }
    }
}
