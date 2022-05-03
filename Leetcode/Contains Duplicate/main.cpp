class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> m;
        for (auto a : nums)
        {
            if (m[a] == 1)
                return true;
            else
                m[a]++;
        }

        return false;
    }
};