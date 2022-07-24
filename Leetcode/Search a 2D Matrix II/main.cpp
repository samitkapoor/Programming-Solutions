class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = 0;
        
        int m = matrix.size();
        int n = matrix[i].size();
        
        
        while(i < m){
            if(matrix[i][0] > target){
                return false;
            }
            if(matrix[i][n-1] < target){
                i++;
            }
            else{
                j = 0;
    
                while(j < n && matrix[i][j] <= target){
                    if(matrix[i][j] == target){
                        return true;
                    }
                    j++;
                }
            
                if(matrix[i][j] > target){
                    n = j;
                }
                
                i++;
            }
        }
        
        return false;
        
    }
};
