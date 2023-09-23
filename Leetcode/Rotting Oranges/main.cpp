class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rottenOranges;

        int counter = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] == 1) {
                    counter++;
                }
                if(grid[i][j] == 2) {
                    rottenOranges.push(make_pair(i,j));
                }
            }
        }

        if(rottenOranges.empty() && counter != 0) return -1;
        if(rottenOranges.empty()) return 0;

        int minutes = 0;
        while(!rottenOranges.empty()) {
            minutes++;
            queue<pair<int, int>> newOranges;;

            while(!rottenOranges.empty()) {
                pair<int, int> curr = rottenOranges.front();
                rottenOranges.pop();

                int i = curr.first;
                int j = curr.second;

                grid[i][j] = 2;

                if(i > 0 && grid[i-1][j] == 1) {
                    counter--;
                    grid[i-1][j] = 2;
                    newOranges.push(make_pair(i-1, j));
                } 
                if(j > 0 && grid[i][j-1] == 1) {
                    counter--;
                    grid[i][j-1] = 2;
                    newOranges.push(make_pair(i, j-1));
                }
                if(i < grid.size()-1 && grid[i+1][j] == 1) {
                    counter--;
                    grid[i+1][j] = 2;
                    newOranges.push(make_pair(i+1, j));
                }
                if(j < grid[0].size()-1 && grid[i][j+1] == 1) {
                    counter--;
                    grid[i][j+1] = 2;
                    newOranges.push(make_pair(i, j+1));
                }
            }

            rottenOranges = newOranges;
        }

        if(counter != 0) return -1; 
        
        return minutes-1;
    }
};
