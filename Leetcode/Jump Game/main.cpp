class Solution {
public:
    bool solve(int ind, vector<int>& nums, vector<bool>& dp) {
        if(ind >= nums.size()) return false;
        if(ind == nums.size()-1) return dp[ind] = true;

        if(dp[ind] != false) return dp[ind];

        bool ans = false;
        for(int i = 1 ; i <= nums[ind] ; i++){
            ans = ans | solve(ind+i, nums, dp);
        }

        return dp[ind] = ans;
    }

    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size()-1] = true;
        if(nums.size() == 1) return true;

        for(int ind = nums.size()-2 ; ind >= 0 ; ind--) {
            bool ans = false;
            for(int i = 1 ; ind+i < nums.size() && i <= nums[ind] ; i++){
                ans = ans | dp[ind+i];
            }

            dp[ind] = ans;
        }
        
        return dp[0];
    }
};
