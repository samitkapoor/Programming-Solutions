#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin>>t;
	
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> nums(n);
	    for(int i = 0 ; i < n ; i++){
	        cin>>nums[i];
	    }
	    
	    bool flag = true;
	    for(int i = 0 ; i< n ; i++){
	        for(int j = i+1 ; j < n ; j++){
	            for(int k = j+1 ; k < n ; k++){
	                if(nums[j] - nums[i] == nums[k] - nums[j]){
	                    flag = false; 
	                    break;
	                }
	            }
	        }
	    }
	    
	    if(!flag) {
	        cout<<"No"<<endl;
	    } else {
	        cout<<"YES"<<endl;
	    }
	}
	return 0;
}
