#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<int> v(n, 0);
	    for(int i=0 ; i<n ; i++){
	        v[i] = i+1;
	    }
	    
	    int half = n/2;
	    for(int i = 0 ; i < half ; i++){
	        cout<<v[i]<<" ";
	    }
	    
	    for(int i = n-1 ; i >= half ; i--) {
	        cout<<v[i]<<" ";
	    }
	    
	    cout<<endl;
	    
	}
	
	return 0;
}
