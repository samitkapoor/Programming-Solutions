class Solution {
public:
    bool solve(string &s1, string &s2, int ind1, int ind2, string &s3, vector<vector<int>>& dp) {
        if(ind1 + ind2 == s3.length()) {
            return 1;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        bool ans = 0;
        if(ind1 < s1.length() && s1[ind1] == s3[ind1+ind2]) {
            ans = ans | solve(s1, s2, ind1+1, ind2, s3, dp);
        }
        if(ind2 < s2.length() && s2[ind2] == s3[ind1+ind2]) {
            ans = ans | solve(s1, s2, ind1, ind2+1, s3, dp);
        }
        return dp[ind1][ind2] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));    

        return solve(s1, s2, 0, 0, s3, dp);
    }
};
