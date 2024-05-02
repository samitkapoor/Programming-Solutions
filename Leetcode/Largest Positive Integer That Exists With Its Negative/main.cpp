class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = INT_MIN;
        unordered_map<int, int> m;
        for(int i = 0 ; i < nums.size() ; i++) {
            m[nums[i]] = 1;
            if(m[-1*nums[i]] != 0) {
                ans = max(ans, nums[i] < 0? -1 * nums[i]: nums[i]);
            }
        }

        return ans == INT_MIN? -1: ans;
    }
};
