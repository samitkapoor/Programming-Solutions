long long findCount(int n, vector<int> &a, vector<int> &b, vector<int> &c){
	vector<int> numsInA(n, 0);
	vector<int> numsInB(n, 0);
	vector<int> numsInC(n, 0);
	for(int i = 0 ; i < n ; i++){
		numsInA[a[i]]++;
		numsInB[b[c[i]]]++;
	}

	long long ans = 0;
	for(int i = 0 ; i < n ; i++){
		ans += numsInA[i] * numsInB[i];
	}

	return ans;
}
