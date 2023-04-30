class Solution {
public:
    int f(int i, int j, string s, string rev_s, int n, vector<vector<int>> &dp) {
        if(i == n || j == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == rev_s[j]) {
            return dp[i][j] = 1 + f(i+1, j+1, s, rev_s, n, dp);
        }

        return dp[i][j] = 0 + max(f(i+1, j, s, rev_s, n, dp), f(i, j+1, s, rev_s, n, dp));
    }

    int longestPalindromeSubseq(string s) {
        //bbbab
        //babbb
        int n = s.length();
        vector<int> next(n+1, 0);

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        for(int i = n-1 ; i >= 0 ; i--) {
            vector<int> curr(n+1, 0);
            for(int j = n-1 ; j >= 0 ; j--) {
                if(s[i] == rev_s[j]) 
                    curr[j] = 1 + next[j+1];
                else 
                    curr[j] = 0 + max(next[j], curr[j+1]);
            }
            next = curr;
        }

        return next[0];
    }
};
