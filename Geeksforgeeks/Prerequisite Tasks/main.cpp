//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[V];
	    for(auto p : prerequisites) {
	        adj[p.first].push_back(p.second);
	    }
	    
	    vector<int> inDegrees(V, 0);
        
        for(int i = 0 ; i < V ; i++){
            for(auto node: adj[i]) {
                inDegrees[node]++;
            }
        }
        
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(inDegrees[i] == 0) {
                q.push(i);
            }
        }
        
        if(q.empty()) return false;
        
        vector<int> topoSort;
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            
            for(auto node: adj[i]) {
                inDegrees[node]--;
                if(inDegrees[node] == 0) q.push(node);
                if(inDegrees[node] < 0) return false;
            }
            
            topoSort.push_back(i);
        }
        
        if(topoSort.size() != V) return false;
        return true;

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
