// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        // first we sort the array because we are going to solve this problem with the help of two pointer algorithm
        sort(A, A + n);

        for (int i = 0; i < n; i++)
        {
            int l = 0, r = n - 1;
            while (l < r)
            {
                // this condition is necessary because we are locking the ith element and we want to find a pair that doesn't include
                // the ith element and all three of those numbers sum up to X
                if (l == i)
                    l++;
                else if (r == i)
                    r--;
                else
                {
                    int temp = A[i] + A[l] + A[r];
                    if (temp == X)
                        return true;
                    else if (temp > X)
                        r--;
                    else
                        l++;
                }
            }
        }

        // if program control reaches here then that means we couldn't find such triplet
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
// } Driver Code Ends