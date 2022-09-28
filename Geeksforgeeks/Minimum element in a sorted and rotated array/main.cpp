//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int search(int arr[], int l, int r)
    {
        
        if(arr[l] < arr[r-1]){
            return arr[l];
        }
        
        while (l <= r)
        {
            int m = l + (r - l) / 2;

            // cout << m << " " << arr[m] << endl;
            if (arr[m] < arr[m - 1])
            {
                return arr[m];
            }
            else if (arr[m] > arr[m + 1])
            {
                return arr[m + 1];
            }
            else if (arr[m] > arr[l])
            {
                l = m;
            }
            else
            {
                r = m - 1;
            }
        }

        return -1;
    }

public:
    int findMin(int arr[], int n)
    {
        // complete the function here
        int x = search(arr, 0, n);

        return x;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
