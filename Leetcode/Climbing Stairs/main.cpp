class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2, 0);
        dp[n] = 1;
        
        for(int i = n-1 ; i >= 0 ; i--) {
            dp[i] = dp[i+1] + dp[i+2];
        }

        return dp[0];
    }
};
