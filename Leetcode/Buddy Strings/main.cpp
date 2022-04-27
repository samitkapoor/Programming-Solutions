class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if ((int)s.length() != (int)goal.length())
            return false;

        if (s == goal)
        {
            set<char> unique_chars;
            for (char c : s)
            {
                unique_chars.insert(c);
            }

            if ((int)unique_chars.size() < (int)s.length())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        vector<int> mis_matches;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
                mis_matches.push_back(i);
        }

        if ((int)mis_matches.size() == 2 &&
            s[mis_matches[0]] == goal[mis_matches[1]] &&
            s[mis_matches[1]] == goal[mis_matches[0]])
            return true;
        return false;
    }
};