class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        
        for(int i=0; i<coins.size() ; i++){
            for(int j=coins[i] ; j<dp.size() ; j++){
                dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
            }
        }
        
        if(dp[amount] == INT_MAX - 1){
            return -1;
        }
        
        return dp[amount];
    }
};
