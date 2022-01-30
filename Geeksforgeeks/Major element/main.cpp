// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {

        // your code here
        int result = a[0]; // storing the current majority element
        int count = 1;     // storing how many times majority element occured
        for (int i = 1; i < size; i++)
        {
            if (result == a[i])
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                    result = a[i], count++;
            }
        }
        count = 0;
        for (int i = 0; i < size; i++)
        {
            if (result == a[i])
                count++;
        }

        if (count <= size / 2)
            return -1;
        return result;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
// } Driver Code Ends