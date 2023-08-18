class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> v(n, 0);
        vector<vector<int>> direction(n, vector<int>(n, 0));

        for(int i = 0 ; i < roads.size() ; i++){
            v[roads[i][0]]++;
            v[roads[i][1]]++;
            direction[roads[i][0]][roads[i][1]] = 1;
            direction[roads[i][1]][roads[i][0]] = 1;
        }

        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                maxi = max(maxi, v[i]+v[j]-direction[i][j]);
            }
        }

        return maxi;
    }
};
