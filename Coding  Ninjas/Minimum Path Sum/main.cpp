#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prevRow(n, 0);
    vector<int> currRow(n, 0);

    prevRow[0] = grid[0][0];

    for(int i=1 ; i<n ; i++){
        prevRow[i] = prevRow[i-1] + grid[0][i]; 
    }

    for(int i=1 ; i< m ; i++){
        for(int j=0 ; j<n ; j++){
            if(j == 0){
                currRow[j] = grid[i][j] + prevRow[j];
            } else{
                currRow[j] = grid[i][j] + min(prevRow[j], currRow[j-1]);
            }
        }

        prevRow = currRow;
    }

    return prevRow[n-1];
}
