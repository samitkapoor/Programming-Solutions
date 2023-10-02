//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        while(!q.empty()) {
            string currWord = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(currWord == targetWord) return level;
            
            for(int i = 0 ; i < currWord.size() ; i++){
                char original = currWord[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    currWord[i] = ch;
                    
                    if(st.find(currWord) != st.end()) {
                        st.erase(currWord);
                        q.push({currWord, level+1});
                    }
                }
                
                currWord[i] = original;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
