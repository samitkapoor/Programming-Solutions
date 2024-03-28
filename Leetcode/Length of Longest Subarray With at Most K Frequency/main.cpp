class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0;
        unordered_map<int, int> m;
        int ans = 0;

        int n = nums.size();

        while(r < n) {
            if(m[nums[r]] == k) {
                ans = max(ans, r - l);

                while(l <= r) {
                    if(nums[l] == nums[r]) break;
                    m[nums[l]]--;
                    l++;
                } 
                l++;
                r++;
            } else {
                m[nums[r]]++;
                r++;
                ans = max(ans, r-l);
            }
        }

        return ans;
    }
};
