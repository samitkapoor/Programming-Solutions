class Solution {
private:
    vector<char> letters{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

public:
    int countWays(int i, string s, vector<int>& dp) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int single = countWays(i+1, s, dp);
        int dbl = 0;
        if(i < s.size()-1 && (s[i] < '2' || (s[i] == '2' && s[i+1] < '7'))) {
            dbl = countWays(i+2, s, dp);
        }

        return dp[i] = single + dbl;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+2, 0);
        dp[s.size()] = 1;

        for(int i = s.size()-1 ; i >= 0 ; i--) {
            if(s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            
            int single = dp[i+1];
            int dbl = 0;
            if(i < s.size()-1 && (s[i] < '2' || (s[i] == '2' && s[i+1] < '7'))) {
                dbl = dp[i+2];
            }

            dp[i] = single + dbl;
        }

        return dp[0];
    }
};
