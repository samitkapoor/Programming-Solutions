class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(n, 0);

        prev = matrix[0];

        for(int i=1 ; i<n ; i++){
            vector<int> curr(n, 0);
            for(int j=0 ; j<n ; j++){
                if(j == 0) {
                    curr[j] = matrix[i][j] + min(prev[j], prev[j+1]);
                }
                else if(j == n-1) {
                    curr[j] = matrix[i][j] + min(prev[j], prev[j-1]);
                }
                else {
                    curr[j] = matrix[i][j] + min(prev[j], min(prev[j-1], prev[j+1]));
                }
            }

            prev = curr;
        }

        int mini = INT_MAX;
        for(int i : prev) {
            mini = min(mini, i);
        }
    
        return mini;
    }

};
