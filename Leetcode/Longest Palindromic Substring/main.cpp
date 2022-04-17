class Solution
{
public:
    string result = "";

    void expandFromMiddle(string s, int l, int r)
    {
        while (l >= 0 && r < (int)s.length() && s[l] == s[r])
        {
            if ((r - l + 1) == s.length())
            {
                result = s;
            }
            else if ((r - l + 1) > (int)result.length())
            {
                result = "";
                for (int i = l; i <= r; i++)
                {
                    result += s[i];
                }
            }

            l--;
            r++;
        }
    }

    string longestPalindrome(string s)
    {
        if (s.length() <= 0)
            return "";
        if (s.length() == 1)
            return s;

        for (int i = 0; i < (int)s.length(); i++)
        {
            expandFromMiddle(s, i, i);
            expandFromMiddle(s, i, i + 1);
        }

        return result;
    }
};