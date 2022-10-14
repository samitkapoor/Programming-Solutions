//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        // code here
        int n = arr.size();
        int l = 0;
        int r = n-1;
        
        vector<int> result(2);
        result[0] = arr[l];
        result[1] = arr[r];
        
        while(l < r){
            int curr = arr[l] + arr[r];
            int sum = result[0] + result[1];
            
            if(abs(sum-x) > abs(curr-x)){
                result[0] = arr[l];
                result[1] = arr[r];
            }
            
            if(curr > x){
                r--;
            }
            else{
                l++;
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
