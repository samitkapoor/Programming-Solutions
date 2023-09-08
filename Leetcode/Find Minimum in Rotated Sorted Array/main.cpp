class Solution {
public:
    int binarySearch(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right) {
            int mid = left + (right - left)/2;

            if(mid != 0 && nums[mid] < nums[mid-1]) return nums[mid];
            else if(nums[mid] >= nums[0]) left = mid+1;
            else right = mid-1;
        }

        return nums[0];
    }

    int findMin(vector<int>& nums) {
        int ans = binarySearch(nums);

        return ans;
    }
};
