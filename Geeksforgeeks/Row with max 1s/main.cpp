// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        // code here
        // to keep track of maximum number of 1s in the row
        int counter = 0;
        // to store the row index with max 1s
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            // to count the number of 1s in the current row
            int temp = 0;
            for (int j = 0; j < m; j++)
            {
                // if element is 1 then increment the temp by 1
                if (arr[i][j] == 1)
                    temp++;
            }

            // if the number of 1s is greater than the maximum number of 1s occured in a row till now
            // then update the result and counter
            if (counter < temp)
            {
                result = i;
                counter = temp;
            }
        }
        // if counter was 0 that means there was no 1 in the matrix in that case we return -1
        if (counter == 0)
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends