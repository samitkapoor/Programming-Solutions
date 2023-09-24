//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int i, vector<int> adj[], vector<int>& edgeColors) { // 0, {{1}, {0, 2}, {1}}, {0, 1, -1}
        edgeColors[i] = 0;
        queue<pair<int, int>> q; // {0, 0} {1, 1}
        q.push({i, 0});
        
        while(!q.empty()) {
            int node = q.front().first; // 0
            int color = (q.front().second == 1)?0:1; // 1
            q.pop();
            
            for(auto curr : adj[node]) {
                if(edgeColors[curr] == -1) {
                    edgeColors[curr] = color;
                    q.push({curr, color});
                } else if(edgeColors[curr] != color) {
                    return false;
                }
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> edgeColors(V, -1);
	    
	    for(int i = 0 ; i < V ; i++){ // 0
	        if(edgeColors[i] == -1) { // -1 -1 -1
	            if(bfs(i, adj, edgeColors) == false) return false;
	        }
	    }
	    
	    return true;
	}
	
	// 3 2 
	// 0 1 
	// 1 2

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
