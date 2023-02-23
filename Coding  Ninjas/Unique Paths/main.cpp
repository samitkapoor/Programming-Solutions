#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<int> currPath(n, 1);
	vector<int> prevRow(n, 1);

	for(int i = 1 ; i < m ; i++){
		for(int j = 1 ; j < n ; j++){
			currPath[j] = prevRow[j] + currPath[j-1];
		}

		prevRow = currPath;
	}

	return currPath[n-1];
}
