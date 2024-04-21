class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> m;

        int size = edges.size();
        if(source == destination) return true;
        if(size == 0) return false;
        
        for(int i = 0 ; i < size ; i++) {
            vector<int> edge = edges[i];
            int from = edge[0];
            int to = edge[1];

            m[from].push_back(to);
            m[to].push_back(from);
        }

        queue<int> visited;
        visited.push(source);
        vector<bool> nodeVisited(n+1, false);

        while(!visited.empty()) {
            int curr = visited.front();
            visited.pop();

            if(!nodeVisited[curr])
                for(int i = 0 ; i < m[curr].size() ; i++) {
                    if(m[curr][i] == destination) return true;
                    visited.push(m[curr][i]);
                }

            nodeVisited[curr] = true;
        }

        return false;
    }
};
