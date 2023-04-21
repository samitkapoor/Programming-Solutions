#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
	vector<int> largest(n, 1), smallest(n, 1);

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < i ; j++){
			if(arr[j] < arr[i]) {
				largest[i] = max(largest[i], largest[j]+1);
			}
		}
	}

	for(int i = n-1 ; i >= 0 ; i--){
		for(int j = n-1 ; j > i ; j--){
			if(arr[j] < arr[i]) {
				smallest[i] = max(smallest[i], smallest[j]+1);
			}
		}
	}

	int maxi = 1;
	for(int i = 0 ; i < n ; i++){
		maxi = max(maxi, largest[i]+smallest[i]-1);
	}

	return maxi;
} 
