int upperBound(vector<int> &arr, int x, int n){
	int l = 0, r = n - 1;
	int answer = n;
	while(l <= r) {
		int mid = l + (r - l)/2;

		if(arr[mid] > x) {
			answer = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return answer;
}
