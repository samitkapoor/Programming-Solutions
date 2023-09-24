//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i, int color, vector<int> adj[], vector<int>& edgeColors) { 
        edgeColors[i] = color;
        
        bool ans = true;
        for(auto node : adj[i]) {
            if(edgeColors[node] == -1) {
                ans = ans & dfs(node, (color==1)?0:1, adj, edgeColors);
            } else if(edgeColors[node] == color) {
                return false;
            }
        }
        
        return ans;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> edgeColors(V, -1);
	    
	    for(int i = 0 ; i < V ; i++){ 
	        if(edgeColors[i] == -1) { 
	            if(dfs(i, 0, adj, edgeColors) == false) return false;
	        }
	    }
	    
	    return true;
	}
	
	

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
