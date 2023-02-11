class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while( l <= r){
            if(s[l++] != s[r--]) return false;
        }

        return true;
    }

    void solve(string s, int index, vector<vector<string>>& result, vector<string> path) {
        if(index == s.size()) {
            result.push_back(path);
            return;
        }

        for(int i = index ; i < s.size() ; i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                solve(s, i + 1, result, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;

        solve(s, 0, result, path);

        return result;
    }
};
