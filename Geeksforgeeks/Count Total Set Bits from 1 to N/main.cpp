// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // calculating the largest power of two that is equal to or less than n because set bits till that number can be
    // easily calculated using the formula (((2^x)/2)*x) where x is the largest power
    int largestPowerOf2(int n)
    {
        int j = 0;

        while ((1 << j) <= n)
        {
            j++;
        }

        return j - 1;
    }

    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        // base condition to stop the recursion
        if (n == 0)
        {
            return 0;
        }

        int x = largestPowerOf2(n);

        // first term - calculates the number of set bits till 2^x using the formula stated above
        // second term - as all the remaining numbers will have their least significant bit set so it adds that number to our answer
        // third term - recursive call to get the set bits of remaining numbers
        return ((1 << (x - 1)) * x) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}
// } Driver Code Ends