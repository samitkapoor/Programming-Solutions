class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x == 0)
            return true;

        if (x < 0)
            return false;

        int reversed_x = 0;
        int forward_x = x;
        while (x > 0)
        {
            int temp = x % 10;
            x = x / 10;

            reversed_x = (long)reversed_x * 10 + temp;
        }

        if (reversed_x == forward_x)
        {
            return true;
        }

        return false;
    }
};