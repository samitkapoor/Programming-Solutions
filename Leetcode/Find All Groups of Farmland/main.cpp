class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> result;

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(land[i][j] == 0) continue;

                queue<pair<int, int>> q;
                vector<int> temp(4, 0);
                temp[0] = i;
                temp[1] = j;
                q.push({i, j});
                while(!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    int _i = curr.first;
                    int _j = curr.second;

                    land[_i][_j] = 0;

                    if(((_i + 1 < m && land[_i+1][_j] == 0) || (_i + 1 == m)) && ((_j + 1 < n && land[_i][_j+1] == 0) || (_j + 1 == n)) && land[i][_j] == 1) {
                        temp[2] = _i;
                        temp[3] = _j;
                    }

                    if(_i + 1 < m && land[_i + 1][_j] == 1) {
                        q.push({_i + 1, _j});
                    }
                    if(_j + 1 < n && land[_i][_j + 1] == 1) {
                        q.push({_i, _j + 1});
                    }
                }

                result.push_back(temp);
            }
        }

        return result;
    }
};
