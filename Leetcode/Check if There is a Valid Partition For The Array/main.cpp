class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp) {
        if(i == -1) return dp[0] = true;

        if(dp[i+1] != -1) return dp[i+1] == 1;
        
        bool ans = false;

        if(i > 0 && nums[i] == nums[i-1]) {
            ans = ans | solve(nums, i-2, dp);
        }
        if(i > 1 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2]) {
            ans = ans | solve(nums, i-3, dp);
        }
        if(i > 1 && nums[i] - 1 == nums[i-1] && nums[i-1] - 1 == nums[i-2]) {
            ans = ans | solve(nums, i-3, dp);
        }

        return dp[i+1] = ans;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        dp[0] = 1;

        return solve(nums,n-1, dp);
    }
};
