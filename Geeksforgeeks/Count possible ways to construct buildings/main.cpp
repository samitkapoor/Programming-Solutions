//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    //space - zero
	    //building - one
	    
	    int endAtSpace = 0;
	    int endAtBuilding = 1;
	    
	    for(int i=0 ; i<N ; i++){
	        int x = endAtSpace;
	        int y = endAtBuilding;
	        endAtSpace = y % 1000000007;
	        endAtBuilding = (x + y) % 1000000007;
	    }
	    
	    long long res = (endAtSpace + endAtBuilding) % 1000000007;
	    
	    return (res * res) % 1000000007 ;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
