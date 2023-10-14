//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet {
    private:
    vector<int> parent, size;
    public:
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findUPar(parent[n]);
    }
    
    void unionBySize(int u, int v){ 
        int pu = findUPar(u);
        int pv = findUPar(v);
        
        if(pu == pv) return;
        
        if(size[pu] < size[pv]) {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        } else {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        int n = details.size();
        unordered_map<string, int> mapMailNode;
        DisjointSet ds = DisjointSet(n);
        sort(details.begin(), details.end());
        for(int i = 0 ; i <n ; i++){
            for(int j = 1 ; j < details[i].size() ; j++){
                if(mapMailNode.find(details[i][j]) == mapMailNode.end()) {
                    mapMailNode[details[i][j]] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[details[i][j]]);
                }
            }
        }
        
        vector<string> mergedMails[n];
        for(auto it: mapMailNode) {
            int node = ds.findUPar(it.second);
            string mail = it.first;
            mergedMails[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0 ; i < n ; i++){
            if(mergedMails[i].size() == 0) continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto s: mergedMails[i]){
                temp.push_back(s);
            }
            
            ans.push_back(temp);   
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends
