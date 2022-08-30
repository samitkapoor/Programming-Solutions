#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    float x1, x2, y1, y2;
	    cin>>x1>>x2>>y1>>y2;
	    
	    if((y1/x1) < (y2/x2)){
	        cout<<"-1"<<endl;
	    }
	    else if((y1/x1) > (y2/x2)){
	        cout<<"1"<<endl;
	    }
	    else{
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
