#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int i = nums.size() - 2;
    // finding the break point : index of the element where nums[i] < nums[i+1]
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;
    // if the break point is greater than or equal to zero
    if (i >= 0)
    {
        // going from left to right and finding the first element that is greater than element at break point
        int j = nums.size() - 1;
        while (nums[j] <= nums[i] && j > i)
            j--;
        // swapping the element at break point and the swap point
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        // reversing the array from (break point + 1) to end
        reverse(nums.begin() + i + 1, nums.end());
    }
    else
        // if break point is negative then we just reverse the whole array
        reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums{1, 3, 2};
    nextPermutation(nums);
    for (int i : nums)
        cout << i << " ";
    return 0;
}