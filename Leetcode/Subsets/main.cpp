class Solution {
public:
    void f(vector<int> &nums, int n, vector<vector<int>> &result, int index, vector<int> &curr) {
        if(index == n) {
            result.push_back(curr);
            return;
        };

        //take 
        curr.push_back(nums[index]);
        f(nums, n, result, index+1, curr);

        // don't take
        curr.pop_back();
        f(nums, n, result, index+1, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        int n = nums.size();

        f(nums, n, result, 0, curr);

        return result;
    }
};
