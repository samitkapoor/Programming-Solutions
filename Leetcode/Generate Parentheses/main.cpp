class Solution
{
public:
    vector<string> parenthesis;

    vector<string> generateParenthesis(int n)
    {
        backtrack("", 0, 0, n);
        return parenthesis;
    }

    void backtrack(string current, int open, int close, int max)
    {
        if ((int)current.length() == 2 * max)
        {
            parenthesis.push_back(current);
            return;
        }

        if (open < max)
            backtrack(current + "(", open + 1, close, max);
        if (close < open)
            backtrack(current + ")", open, close + 1, max);
    }
};