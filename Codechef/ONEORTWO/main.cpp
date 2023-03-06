#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int one, two;
	    cin>>one>>two;
	    
	    if(one == two && one % 2 == 0) {
	        cout<<"CHEFINA"<<endl;
	        continue;
	    }
	    
	    if(one == two && one % 2 != 0) {
	        cout<<"CHEF"<<endl;
	        continue;
	    }
	    
	    int x = abs(one - two);
	    
	    if(one > two && x >= 2) {
	        cout<<"CHEF"<<endl;
	        continue;
	    }
	    
	    if(two > one && x >= 2) {
	        cout<<"CHEFINA"<<endl;
	        continue;
	    }
	    
	    if(one > two && x == 1 && one % 2 != 0) {
	        cout<<"CHEFINA"<<endl;
	        continue;
	    }
	    
	    if(one > two && x == 1 && one % 2 == 0) {
	        cout<<"CHEF"<<endl;
	        continue;
	    }
	    
	    if(two > one && x == 1 && two % 2 != 0) {
	        cout<<"CHEFINA"<<endl;
	        continue;
	    }
	    
	    else {
	        cout<<"CHEF"<<endl;
	        continue;
	    }
	}
	return 0;
}
