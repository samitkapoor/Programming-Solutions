#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    string s;
	    cin>>s;
	    
	    int n = s.length();
	    int counter = 0;
	    int answer = 0;
	    
	    for(int i = 1 ; i < n ; i++){
	        if(s[i] != s[0] and s[i] != s[n-1]){
	            counter++;
	        }
	        else{
	            counter = 0;
	        }
	        
	        answer = max(counter, answer);
	    }
	    
	    if(answer == 0){
	        cout<<"-1"<<endl;
	    }
	    else{
	        cout<<answer<<endl;
	    }
	}
	return 0;
}
