//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int, int>> adj[n];
        for(int i = 0 ; i < flights.size() ; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            
            adj[u].push_back({v, price});
        }
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> distances(n, INT_MAX);
        distances[src] = 0;
        
        while(!q.empty()) {
            int stops = q.front().first;
            int location = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stops > K) continue;
            
            for(auto flight: adj[location]) {
                int destination = flight.first;
                int price = flight.second;
                
                if(cost + price < distances[destination] && stops <= K) {
                    distances[destination] = cost + price;
                    q.push({stops+1, {destination, distances[destination]}});
                }
            }
        }
        
        return distances[dst] == INT_MAX? -1: distances[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
