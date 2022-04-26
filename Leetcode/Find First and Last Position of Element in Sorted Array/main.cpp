class Solution
{
public:
    int leftMost(vector<int> nums, int l, int r, int target)
    {
        while (l <= r && l < (int)nums.size())
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target && (m == 0 || nums[m - 1] != target))
            {
                return m;
            }
            else if (nums[m] >= target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return -1;
    }

    int rightMost(vector<int> nums, int l, int r, int target)
    {
        while (l <= r && l < (int)nums.size())
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target && (m + 1 == (int)nums.size() || nums[m + 1] != target))
            {
                return m;
            }
            else if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if ((int)nums.size() == 0)
            return {-1, -1};
        vector<int> result(2);
        result[0] = leftMost(nums, 0, (int)nums.size(), target);
        result[1] = rightMost(nums, 0, (int)nums.size(), target);
        return result;
    }
};