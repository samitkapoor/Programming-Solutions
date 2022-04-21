class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = (int)height.size();
        int l = 0, r = n - 1;
        int result = 0;
        while (l < r)
        {
            int t = min(height[l], height[r]);
            result = max(result, (t * (r - l)));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return result;
    }
};