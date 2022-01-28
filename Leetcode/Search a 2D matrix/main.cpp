#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution ob;
    vector<vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    bool result = ob.searchMatrix(input, 3);
    cout << result << endl;
    return 0;
}