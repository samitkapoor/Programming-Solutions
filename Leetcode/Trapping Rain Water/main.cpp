class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> leftMax(height.size(), height[0]);
        vector<int> rightMax(height.size(), height[height.size() - 1]);
        int result = 0;

        for (int i = 1; i < height.size(); i++)
        {
            if (leftMax[i - 1] > height[i])
            {
                leftMax[i] = leftMax[i - 1];
            }
            else
            {
                leftMax[i] = height[i];
            }
        }

        for (int i = height.size() - 2; i >= 0; i--)
        {
            if (rightMax[i + 1] > height[i])
            {
                rightMax[i] = rightMax[i + 1];
            }
            else
            {
                rightMax[i] = height[i];
            }
        }

        for (int i = 1; i < height.size() - 1; i++)
        {
            if (height[i] < leftMax[i] && height[i] < rightMax[i])
            {
                result += min(leftMax[i], rightMax[i]) - height[i];
            }
        }

        return result;
    }
};