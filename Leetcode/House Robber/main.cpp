class Solution {
public:

    int rob(vector<int>& nums) {
        int plusTwo = 0;
        int plusOne = 0;

        int ans = 0;

        for(int i = nums.size()-1 ; i >= 0 ; i--) {
            int rob = nums[i] + plusTwo;
            int dontRob = 0 + plusOne;

            ans = max(rob, dontRob);

            plusTwo = plusOne;
            plusOne = ans;
        }

        return ans;
    }
};
