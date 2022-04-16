class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;

        vector<int> levels(s.length(), 0);
        bool add = true;
        int level = 1;

        for (int i = 0; i < s.length(); i++)
        {
            levels[i] = level;

            if (level == numRows)
            {
                add = false;
            }
            else if (level == 1)
            {
                add = true;
            }

            if (add)
            {
                level++;
            }
            else
            {
                level--;
            }
        }

        string result = "";
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < s.length(); j++)
            {
                if (levels[j] == (i + 1))
                {
                    result += s[j];
                }
            }
        }

        return result;
    }
};