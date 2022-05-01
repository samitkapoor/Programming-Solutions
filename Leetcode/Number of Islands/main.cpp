class Solution
{
public:
    vector<vector<char>> gridt;

    int numIslands(vector<vector<char>> &grid)
    {
        gridt = grid;
        int result = 0;
        for (int i = 0; i < (int)grid.size(); i++)
        {
            for (int j = 0; j < (int)grid[i].size(); j++)
            {
                if (gridt[i][j] == '1')
                {
                    result += 1;
                    cover(i, j);
                }
            }
        }
        return result;
    }

    void cover(int i, int j)
    {
        if (i < 0 || i >= (int)gridt.size() || j < 0 || j >= (int)gridt[i].size() || gridt[i][j] == '0')
        {
            return;
        }

        gridt[i][j] = '0';
        cover(i + 1, j);
        cover(i - 1, j);
        cover(i, j + 1);
        cover(i, j - 1);
    }
};