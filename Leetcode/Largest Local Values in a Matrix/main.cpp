class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));

        vector<int> di{-1, 0, 1};
        vector<int> dj{-1, 0, 1};

        for(int i = 1 ; i < n - 1 ; i++) {
            for(int j = 1 ; j < n - 1 ; j++) {
                int maxi = 0;
                for(int k = 0 ; k < 3 ; k++) {
                    int xi = i + di[k];
                    for(int l = 0 ; l < 3 ; l++) {
                        int xj = j + dj[l];
                        maxi = max(maxi, grid[xi][xj]);
                    }
                }

                ans[i-1][j-1] = maxi;
            }
        }

        return ans;
    }
};
