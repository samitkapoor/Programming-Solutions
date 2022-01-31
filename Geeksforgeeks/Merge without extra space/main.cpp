// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void merge(int one[], int two[], int n, int m)
    {
        // code here
        // we start iterating in one from the end and in two from the beginning
        int i = n - 1, j = 0;
        // we loop through every elements and check if one[i] is greater than or equal to two[j]
        // if this is the case then we swap those elements
        // and we increment j and decrement i in every iteration to keep the loop running
        while (i >= 0 && j < m)
        {
            if (one[i] >= two[j])
            {
                int temp = one[i];
                one[i] = two[j];
                two[j] = temp;
            }
            i--, j++;
        }

        // lastly we sort both arrays using quicksort
        sort(one, one + n);
        sort(two, two + m);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends