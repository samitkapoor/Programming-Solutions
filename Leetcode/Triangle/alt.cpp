class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> prev(n, 0);
        prev[0] = triangle[0][0];

        if(n == 1) return prev[0];

        for(int i=1 ; i<n ; i++){
            vector<int> curr(n, 0);
            for(int j=0 ; j<triangle[i].size() ; j++){
                if(j == 0) curr[j] = prev[j] + triangle[i][j];
                else if(j == triangle[i].size()-1) curr[j] = prev[j-1] + triangle[i][j];
                else curr[j] = triangle[i][j] + min(prev[j], prev[j-1]);
            }

            prev = curr;
        }

        int mini = INT_MAX;
        for(int i : prev){
            mini = min(i , mini);
        }

        return mini;        
    }
};
