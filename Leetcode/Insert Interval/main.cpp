class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) {
            return {newInterval};
        } 
        vector<vector<int>> newIntervals;

        vector<int> combinedInterval{INT_MAX, INT_MAX};

        for(vector<int>& interval: intervals) {
            if((newInterval[0] > interval[1]) || (newInterval[1] < interval[0])) {
                if((newInterval[1] < interval[0]) && combinedInterval[0] != -1) {
                    if(combinedInterval[0] == INT_MAX) newIntervals.push_back(newInterval);
                    else newIntervals.push_back(combinedInterval);
                    combinedInterval[0] = combinedInterval[1] = -1;
                }
                newIntervals.push_back(interval);
            } else {
                if(combinedInterval[0] == INT_MAX) {
                    combinedInterval[0] = min(interval[0], newInterval[0]);
                } 

                combinedInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        if(combinedInterval[0] != -1 && combinedInterval[0] != INT_MAX) {
            newIntervals.push_back(combinedInterval);
        }

        if(intervals.size() == 1 && newIntervals.size() == 0) {
            return {combinedInterval};
        } else if(combinedInterval[0] == INT_MAX) {
            newIntervals.push_back(newInterval);
        } else if(intervals.size() > 1 && newIntervals.size() == 0) {
            return {combinedInterval};
        }

        return newIntervals;
    }
};
