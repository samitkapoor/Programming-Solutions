class Solution {
public:
    int profit(vector<int>& nums, int start, int end) {
        int plusTwo = 0;
        int plusOne = 0;

        int ans = 0;

        for(int i = end-1 ; i >= start ; i--) {
            int rob = nums[i] + plusTwo;
            int dontRob = 0 + plusOne;

            ans = max(rob, dontRob);

            plusTwo = plusOne;
            plusOne = ans;
        }

        return ans;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        return max(profit(nums, 1, nums.size()), profit(nums, 0, nums.size()-1));
    }
};
