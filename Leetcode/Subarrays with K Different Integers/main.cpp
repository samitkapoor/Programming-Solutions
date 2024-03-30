class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        int l = 0 , r = 0 , n = nums.size(), ans = 0;

        while(r<n) {
            m[nums[r]]++;
            while(m.size() > k) {
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            ans += r - l + 1;
            r++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarrays(nums, k) - countSubarrays(nums, k - 1);
    }
};
