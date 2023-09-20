class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxLength = -1;

        int totalSum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            totalSum += nums[i];
        }

        int right = 0, left = 0;
        int currSum = 0;
        while(right < nums.size()) {
            currSum += nums[right];
            
            while(left <= right && currSum > totalSum - x) {
                currSum -= nums[left++];
            }
            if(currSum == totalSum - x) {
                maxLength = max(maxLength, right - left + 1);
            }

            right++;
        }

        return maxLength == -1 ? -1: nums.size() - maxLength;
    }
};
