class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int temp = nums[i] + nums[l] + nums[r];
                if (temp == 0)
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    int x = nums[r];
                    while (nums[r] == x && r > l)
                    {
                        r--;
                    }
                }
                else if (temp > 0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }

        map<vector<int>, int> m;
        n = (int)result.size();
        vector<vector<int>> actResult;
        for (int i = 0; i < n; i++)
        {
            if (m[result[i]] == 0)
                actResult.push_back(result[i]);
            m[result[i]]++;
        }

        return actResult;
    }
};