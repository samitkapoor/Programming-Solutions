class Solution {
public:
    bool isPairsPossible(vector<int>&nums, int p, int difference) {
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] - nums[i-1] <= difference) {
                p--;
                i++;
            }
        }

        return p <= 0;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[nums.size()-1]-nums[0];
        int ans = right;
        while(left<=right) {
            int mid = left + (right-left)/2;
            if(isPairsPossible(nums, p, mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return ans;
    }
};
