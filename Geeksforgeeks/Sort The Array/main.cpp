//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int partition(vector<int>& arr, int low, int high){
        int pivot = arr[high];
        int i = low-1;
        
        for(int j=low ; j<=high-1 ; j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        
        return i+1;
    }
    
    void sortTheArray(vector<int>& arr, int low, int high){
        if(high > low){
            int p = partition(arr, low, high);
            sortTheArray(arr, low, p-1);
            sortTheArray(arr, p+1, high);
        }
    }
    
    public:
    vector<int> sortArr(vector<int>arr, int n){
        sortTheArray(arr, 0, n-1);
        return arr;
    }
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends
