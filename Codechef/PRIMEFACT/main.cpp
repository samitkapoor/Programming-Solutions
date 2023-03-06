#include <bits/stdc++.h>
using namespace std;

int smallestPrime(int target){
    if(target % 2 == 0 ) return 2;
    
    for(int i = 3; i<=sqrt(target) ; i+=2){
        if(target % i == 0) return i;
    }
    
    return target;
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int initScore, sum;
	    cin>>initScore>>sum;
	    
	    int timer = 0;
	    while(initScore < sum) {
	        if(initScore % 2 == 0){
	            int temp = sum - initScore + 1;
	            temp = temp/2;
	            timer += temp;
	            break;
	        }
	        else {
	            initScore += smallestPrime(initScore);
	            timer++;
	        }
	    }
	    
	    cout<<timer<<endl;
	}
	
	return 0;
}
