class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        int counter = 0;
        int minHeight = INT_MAX;

        for(int i = 0 ; i < points.size() ; i++){
            if(minHeight < points[i][0] && i == points.size()-1) {
                counter+=2;
                continue;
            } else if(minHeight < points[i][0] || i == points.size()-1) {
                counter++;
                minHeight = points[i][1];
                continue;
            }
            minHeight = min(points[i][1], minHeight);
        }

        return counter;
    }
};
//counter = 1
//minHeight = 
//[[1,2],[3,4],[5,6],[7,8]]
