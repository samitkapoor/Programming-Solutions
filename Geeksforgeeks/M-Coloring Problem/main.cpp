//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool possible(bool graph[101][101], int color, int index, vector<int> colors) {
        for(int edge = 0 ; edge < colors.size() ; edge++){
            if((graph[edge][index] == true && colors[edge] == color) || (graph[index][edge] == true && colors[edge] == color)) {
                return false;
            }
        }
        
        return true;
    }

    bool solve(bool graph[101][101], int m, int n, vector<int>& colors, int index) {
        if(index == n) return true;
        
        for(int color = 0 ; color < m ; color++) {
            if(possible(graph, color, index, colors)){
                colors[index] = color;
                bool val = solve(graph, m, n, colors, index+1);
                if(val == true){
                    return true;
                }
                colors[index] = -1;
            }
        }
        
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colors(n, -1);
        return solve(graph, m, n, colors, 0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
