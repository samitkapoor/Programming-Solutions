//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    vector<int> endAt0(n+2, 0);
	    vector<int> endAt1(n+2, 0);
	    
	    endAt1[1] = 1;
	    
	    for(int i = 2 ; i <= n+1 ; i++){
	        endAt0[i] = endAt1[i-1] % 1000000007;
	        endAt1[i] = (endAt0[i-1] + endAt1[i-1]) % 1000000007;
	    }
	    
	    return (endAt0[n+1] + endAt1[n+1])%1000000007;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
