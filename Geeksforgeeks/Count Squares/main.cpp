// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countSquares(int N)
    {
        // code here
        // result variable: to store the number of squares
        int result = 0;
        // temporary variable using which we check how many squares are less than N
        int i = 1;
        while ((i * i) < N)
        {
            i++;
            result++;
        }

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
        int N;

        cin >> N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
} // } Driver Code Ends