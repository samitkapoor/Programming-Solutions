//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> v(n, 0);
        for(int i=0 ; i<n ; i++){
            v[arr[i]]++;
        }
        
        vector<int> result;
        for(int i=0 ; i<n ; i++){
            if(v[i] > 1){
                result.push_back(i);
            }
        }
        
        if(result.size() == 0){
            return {-1};
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
