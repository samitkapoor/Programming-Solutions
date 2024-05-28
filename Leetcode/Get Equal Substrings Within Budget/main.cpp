class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        int len = 0;
        int left = 0;
        int right = 0;
        int currCost = 0;

        while (left < n && right < n)
        {
            int rightDiff = abs(s[right] - t[right]);
            int leftDiff = abs(s[left] - t[left]);

            if (rightDiff + currCost <= maxCost)
            {
                currCost += rightDiff;
                right++;
            }
            else
            {
                currCost -= leftDiff;
                left++;
            }

            if (currCost <= maxCost && len < right - left)
            {
                len = right - left;
            }
        }

        return len;
    }
};
