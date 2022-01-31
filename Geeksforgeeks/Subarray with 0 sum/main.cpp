// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        // Your code here
        // we will be using map to solve this problem
        int temp = arr[0];
        unordered_map<int, int> Map;
        Map.insert(make_pair(temp, 1));
        for (int i = 1; i < n; i++)
        {
            // we will add every number and in every iteration we check if the current sum (temp) is present
            // in the map or not, if current sum is not present in the map then we insert the value inside the map
            // else we return true if current sum is found in the map because that means the numbers that appeared after
            // the current sum in previous iterations all summed up to zero, hence creating a subarray with sum 0
            temp = arr[i] + temp;
            if (Map.find(temp) == Map.end())
                Map.insert(make_pair(temp, 1));
            else
                return true;

            // if at any point temp becomes 0 then we also return true
            if (temp == 0)
                return true;
        }

        // if the program control reaches here then that means we could not find any subarray that summed up to 0
        //  hence, we return false
        return false;
    }
};

// { Driver Code Starts.
// Driver code
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
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} // } Driver Code Ends