#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<int> v(n);
	    for(int i=0 ; i<n ; i++){
	        cin>>v[i];
	    }
	    
	    int odd, eve, two;
	    
	    odd = eve = two = 0;
	    
	    for(int i : v){
	        if ( i == 2 ) 
	            two++;
	        else if ( i % 2 == 0 ) 
	            eve++;
	        else
	            odd++;
	    }
	    
	    if( odd % 2 == 0 ){
	        cout<<0<<endl;
	    }
	    else if( odd % 2 != 0 ) {
            if( two != 0 )
                cout<<1<<endl;
            else
                cout<<-1<<endl;
	    }
	}
	return 0;
}
