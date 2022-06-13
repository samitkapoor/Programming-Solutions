class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1 ; i<(int)triangle.size() ; i++){
            for(int j=i ; j>=0 ; j--){
                int sum = 0;
                if(j == 0){
                    sum = triangle[i-1][j] + triangle[i][j];
                }
                else if(j == i){
                    sum = triangle[i-1][j-1] + triangle[i][j];
                }
                else{
                    sum = min(triangle[i-1][j]+triangle[i][j], triangle[i][j]+triangle[i-1][j-1]);
                }
                
                triangle[i][j] = sum;
            }
        }
        
        sort(triangle[(int)triangle.size()-1].begin(), triangle[(int)triangle.size()-1].end());
        
        return triangle[(int)triangle.size()-1][0];       
        
    }
};
