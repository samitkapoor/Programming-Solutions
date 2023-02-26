#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);

    prev = matrix[0];

    for (int i = 1; i < n; i++) {
        vector<int> curr(m,0);
        for (int j = 0; j < m; j++) {
            if(j == 0) {
                curr[j] = matrix[i][j] + max(prev[j], prev[j+1]);
            } else if (j == m-1) {
                curr[j] = matrix[i][j] + max(prev[j], prev[j-1]);
            } else {
                curr[j] = matrix[i][j] + max(prev[j], max(prev[j+1], prev[j-1]));
            }
        }

        prev = curr;
    }

    int maxi = INT_MIN;
    for(int i : prev) {
        maxi = max(i, maxi);
    }

    return maxi;
}
