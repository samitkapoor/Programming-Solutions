class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> result(numRows);

        vector<int> x = {1};
        result[0] = x;
        if (numRows == 1)
            return result;

        int i = 1;
        while (i < numRows)
        {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 0; j < (int)result[i - 1].size() - 1; j++)
            {
                temp.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            }
            temp.push_back(1);

            result[i] = temp;
            i++;
        }

        return result;
    }
};