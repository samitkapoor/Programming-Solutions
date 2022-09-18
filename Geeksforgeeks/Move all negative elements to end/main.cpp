//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        queue<int> positives;
        queue<int> negatives;
        
        for(int i=0 ; i<n ; i++){
            if(arr[i] < 0){
                negatives.push(arr[i]);
            }
            else{
                positives.push(arr[i]);
            }
        }
        
        int k = 0;
        while(!positives.empty()){
            arr[k++] = positives.front();
            positives.pop();
        }
        
        while(!negatives.empty()){
            arr[k++] = negatives.front();
            negatives.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends
