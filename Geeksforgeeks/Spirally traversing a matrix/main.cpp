// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        int minr = 0;
        int minc = 0;
        int maxr = matrix.size() - 1;
        int maxc = matrix[0].size() - 1;
        int size = matrix.size() * matrix[0].size();
        vector<int> result(size);
        int x = 0;

        while (x < size)
        {
            // top wall
            for (int i = minr, j = minc; j <= maxc && x < size; j++)
            {
                result[x++] = matrix[i][j];
            }
            minr++;

            // right wall
            for (int i = minr, j = maxc; i <= maxr && x < size; i++)
            {
                result[x++] = matrix[i][j];
            }
            maxc--;

            // bottom wall
            for (int i = maxr, j = maxc; j >= minc && x < size; j--)
            {
                result[x++] = matrix[i][j];
            }
            maxr--;

            // left wall
            for (int i = maxr, j = minc; i >= minr && x < size; i--)
            {
                result[x++] = matrix[i][j];
            }
            minc++;
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends