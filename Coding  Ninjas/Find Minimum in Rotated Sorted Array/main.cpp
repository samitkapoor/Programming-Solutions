int findMin(vector<int>& arr)
{
	int l = 0, r = arr.size()-1;
	while(l <= r) {
		int m = l + (r - l)/2; //0
		if(m != 0 && arr[m] < arr[m-1]) return arr[m]; //false
		else if(arr[m] >= arr[0]) l = m + 1; //false
		else r = m - 1; //0, 1
	}

	return arr[0];
}
