class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 2;

        while( l <= r ){
            int mid = l + (r-l)/2;

            if(mid % 2 == 0) {
                if(nums[mid+1] != nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            } else {
                if(nums[mid-1] != nums[mid]){
                    r = mid-1;
                } else{
                    l = mid + 1;
                }
            }
        }

        return nums[l];
    }
};
