class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++)
        {
            sort_diagonal(mat, i, 0);
        }

        for (int i = 0; i < cols; i++)
        {
            sort_diagonal(mat, 0, i);
        }

        return mat;
    }

    void sort_diagonal(vector<vector<int>> &mat, int x, int y)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        int i = x;
        int j = y;

        vector<int> v(101, 0);
        while (i < rows && j < cols)
        {
            v[mat[i][j]]++;

            i++;
            j++;
        }

        i = x;
        j = y;

        for (int k = 0; k < 101; k++)
        {
            while (v[k] > 0)
            {
                mat[i][j] = k;

                v[k]--;
                i++;
                j++;
            }
        }
    }
};
