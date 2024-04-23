class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> inDegree(n, 0);
        unordered_map<int, vector<int>> m;
        for(int i = 0 ; i < edges.size() ; i++) {
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> leafs;
        for(int i = 0 ; i < n ; i++) {
            if(inDegree[i] == 1) leafs.push(i);
        }

        vector<int> visited(n, 0);
        int processed = 0;
        while(n - processed > 2) {
            int size = leafs.size();
            processed += size;
            while(size--) {
                int curr = leafs.front();
                leafs.pop();

                visited[curr] = 1;
                for(int adj: m[curr]) {
                    if(--inDegree[adj] == 1) {
                        leafs.push(adj);
                    }
                }
            }
        }

        vector<int> mht;
        while(!leafs.empty()) {
            mht.push_back(leafs.front());
            leafs.pop();
        }

        return mht;
    }
};
