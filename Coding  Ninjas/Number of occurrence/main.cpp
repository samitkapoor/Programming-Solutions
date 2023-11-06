int lower_bound(vector<int> &arr, int x) {
    int left = 0;
    int right = arr.size()-1;
    int ans = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == x) {
            ans = mid;
            right = mid-1;
        } else if(arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int upper_bound(vector<int> &arr, int k) {
	int left = 0;
	int right = arr.size()-1;
	int ans = arr.size();

	while(left <= right) {
		int mid = left + (right-left)/2;
		if(arr[mid] <= k) {
			left = mid + 1;
		} else {
			right = mid - 1;
			ans = mid;
		}
	} 

	return ans;
}

int count(vector<int>& arr, int n, int k) {
	int a = lower_bound(arr, k);
	int b = upper_bound(arr, k);
	// cout<<a<<endl<<b<<endl;

	if(arr[a] != k) return 0;
	if(b == arr.size()) return b-a;

	// cout<<a<<""<<b<<endl;

	return b - a;
}
