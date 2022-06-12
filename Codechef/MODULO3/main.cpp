#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a, b;
	    cin>>a>>b;
	    bool flag = true;
	   // cout<<"NEW"<<endl;
        int counter = 0;
	    do{
	       // cout<<a<<" "<<b<<endl;
	       // cout<<counter<<endl;
	        if(((a%3)==0) || ((b%3)==0)){
	            cout<<counter<<endl;
	            flag = false;
	        }
	        else if(a >= b){
	            a = a-b;
	            counter++;
	        }
	        else{
	            b = b-a;
	            counter++;
	        }
	    }while(flag);
	}
	return 0;
}
