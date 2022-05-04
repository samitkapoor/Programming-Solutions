class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result(2, -1);
        int n = (int)numbers.size();
        int l = 0, r = n - 1;

        while (l < r)
        {
            int t = numbers[l] + numbers[r];

            if (t == target)
            {
                result[0] = l + 1;
                result[1] = r + 1;

                return result;
            }
            else if (t > target)
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return result;
    }
};