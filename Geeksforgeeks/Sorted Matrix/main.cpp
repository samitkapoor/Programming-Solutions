// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
    {
        // code here
        // idea is to store all the elements of the matrix in a linear array and then sort the linear array
        // then place all the elements of the sorted linear array in the matrix one by one
        vector<int> sortArray(Mat.size() * Mat[0].size(), 0);
        int k = 0;
        for (int i = 0; i < Mat.size(); i++)
        {
            for (int j = 0; j < Mat[i].size(); j++)
            {
                sortArray[k++] = Mat[i][j];
            }
        }

        sort(sortArray.begin(), sortArray.end());

        k = 0;
        for (int i = 0; i < Mat.size(); i++)
        {
            for (int j = 0; j < Mat[i].size(); j++)
            {
                Mat[i][j] = sortArray[k++];
            }
        }

        return Mat;
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
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << v[i][j] << " ";
            cout << "\n";
        }
    }
} // } Driver Code Ends