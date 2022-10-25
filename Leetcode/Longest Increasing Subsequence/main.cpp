class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        int result = 0;
        for(int i=1 ; i<n ; i++){
            dp[i] = 1;
            for(int j=0 ; j<i ; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        for(int i=0 ; i<n ; i++){
            result = max(result, dp[i]);
        }
        
        return result;
    }
};
