//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int a, b;
        
        for(int i=0 ; i<n ; i++){
            int val = arr[i];
            
            if(arr[abs(val)-1] < 0){
                a = val;
            }
            else{
                arr[abs(val)-1] *= -1;
            }
        }
        
        for(int i=0 ; i <n ; i++){
            if(arr[i] > 0){
                b = i+1;
                break;
            }
        }
        
        int *res = new int[2];
        res[0] = abs(a);
        res[1] = b;
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
