class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(26, 0);
        dp[s[n-1]-'a'] = 1;

        for(int i = n - 2 ; i >= 0 ; i--) {
            int ans = 0;
            int l = max(0, s[i] - 'a' - k);
            int r = min(25, s[i] - 'a' + k);
            for(int t = l ; t <= r ; t++) {
                ans = max(ans, dp[t]);
            }
            dp[s[i] - 'a'] = max(dp[s[i]-'a'], ans + 1);
        }

        int ans = 0;
        for(int i = 0 ; i < 26 ; i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
