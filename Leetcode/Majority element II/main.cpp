#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{

    map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }

    vector<int> result;

    for (auto x : m)
    {
        if (x.second > nums.size() / 3)
        {
            result.push_back(x.first);
        }
    }

    return result;
}

int main()
{
    vector<int> nums{3, 2, 3};
    vector<int> result = majorityElement(nums);
    for (int i : result)
        cout << i << " ";
    return 0;
}
