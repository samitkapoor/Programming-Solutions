#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int h, x, y;
	    cin>>h>>x>>y;
	    
	    int moves = 0;
	    h = h - y;
	    moves++;
	    
	    if(h > 0) {
	        moves += ceil((float)h/x);
	    }
	    
	    cout<<moves<<endl;
	}
	return 0;
}
