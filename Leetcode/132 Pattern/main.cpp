class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> stk;
        int currMin = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            while(!stk.empty() && nums[i] >= stk.top().first) stk.pop();
            if(!stk.empty() && nums[i] > stk.top().second) {
                return true;
            }

            stk.push(make_pair(nums[i], currMin));
            currMin = min(currMin, nums[i]);
        }

        return false;
    }
};
