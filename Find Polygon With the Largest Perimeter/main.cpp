class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i];
        }

        long long result = 0;
        for(int i = nums.size()-1 ; i >= 0 ; i--) {
            sum -= nums[i];
            if(sum > nums[i]) {
                return sum + nums[i];
            }
        }

        return -1;
    }
};
