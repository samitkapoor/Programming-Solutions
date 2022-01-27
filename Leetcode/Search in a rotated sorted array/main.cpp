#include <bits/stdc++.h>

using namespace std;

// a modified binary search to find the pivot point
int pivotPoint(vector<int> nums)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        // if this condition satisfies then we have found the pivot point
        if (m == 0 || nums[m] < nums[m - 1])
        {
            return m;
        }
        // if the middle element is greater than the rightmost element then that means we are in the first half
        // of the array i.e. the pivot belongs after the mid point
        else if (nums[m] > nums[r])
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    return 0;
}

// regular binary search function
int binarySearch(vector<int> nums, int l, int r, int target)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] == target)
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

int search(vector<int> &nums, int target)
{
    // this condition is necessary to remove the index out of bounds error
    if (nums[nums.size() - 1] == target)
        return nums.size() - 1;
    // using binary search to find the pivot point i.e. if m is the pivot point then a[m] < a[m-1]
    int pivot = pivotPoint(nums);
    int x = -1, y = -1;
    // now that we have found the pivot, we can divide the array into two parts, and run separate binary searches each binary search for one side
    if (pivot != 0)
        x = binarySearch(nums, 0, pivot - 1, target);
    y = binarySearch(nums, pivot, nums.size() - 1, target);
    // as the element will be in only one half so the other half will be returning -1, which can not be bigger than the index of the target
    return max(x, y);
}

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int x = 3;
    int y = search(nums, x);
    cout << y << endl;
    return 0;
}