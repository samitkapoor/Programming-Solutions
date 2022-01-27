#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    if (intervals.size() == 1)
        return intervals;
    // sorting the intervals vector
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
         { return tie(a[0], a[1]) < tie(b[0], b[1]); });

    vector<vector<int>> result;
    vector<int> interval{intervals[0][0], intervals[0][1]};

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> element = intervals[i];
        // this condition checks if there is a overlap
        if (interval[1] >= element[0])
        {
            // if the intervals overlap then we expand the interval
            interval[1] = max(interval[1], element[1]);
            interval[0] = min(interval[0], element[0]);
        }
        else
        {
            // if the intervals do not overlap then we push the interval in the result
            result.push_back(interval);
            // and initialize the interval with new values
            interval[0] = element[0];
            interval[1] = element[1];
        }
    }

    // pushing the last remaining interval
    result.push_back(interval);

    return result;
}

int main()
{
    vector<vector<int>> input{{1, 4}, {0, 0}};
    input = merge(input);

    for (vector<int> x : input)
    {
        printf("[%d, %d]", x[0], x[1]);
    }
    return 0;
}