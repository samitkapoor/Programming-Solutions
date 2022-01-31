// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {
        // code here

        // we will be storing the count of subarray in result variable
        ll result = 0;
        // we will be calculating the sum of all the elements in the array in this temp variable
        int temp = arr[0];

        // if temp == 0 that means the first element was zero, so we increment the result by 1
        if (temp == 0)
            result++;

        // we will be using the help of maps to store the sums on each iteration and their frequencies
        map<int, int> m;
        // we insert the first subarray and it's frequency
        m.insert(make_pair(temp, 1));

        for (int i = 1; i < n; i++)
        {
            // adding the current element in the temp variable
            temp += arr[i];
            // if it is zero then it means the sum of the array was zero so we increment the result variable
            if (temp == 0)
                result++;

            // if the current sum (temp) is found in the map that means it has occured previously and the number leading forward
            // to that number sum up to zero so we add the frequency of how many times the sum has occured in the result variable
            if (m.find(temp) != m.end())
                result += m[temp];

            // lastly we enter the current sum and it's frequency in the map
            m[temp]++;
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
        int n;
        cin >> n; // input size of array

        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; // input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
} // } Driver Code Ends