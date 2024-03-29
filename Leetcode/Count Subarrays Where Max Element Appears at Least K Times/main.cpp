class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;

        int target = 0;
        for(int num : nums) {
            target = max(target, num);
        }

        int l = 0, r = 0, freq = 0;
        while(r < n) {
            if(nums[r] == target) freq++;

            if(freq >= k) {
                while(nums[l] != target) {
                    ans += n - r;
                    l++;
                }
                ans+=n-r;
                l++;
                freq--;
            }

            r++;
        }

        return ans;
    }
};
