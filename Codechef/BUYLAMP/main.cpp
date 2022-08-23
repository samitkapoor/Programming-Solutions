#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
        int n, k, x, y;
        cin>>n>>k>>x>>y;
        
        if(x <= y){
            cout<<n*x<<endl;
        }
        else if(y < x){
            cout<<(k*x)+((n-k)*y)<<endl;
        }
	}
	return 0;
}
