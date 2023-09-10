class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numSum = 0;
        int totalSum = 0;

        for(int i = 0 ; i <= nums.size() ; i++){
            totalSum += i;

            if(i != nums.size()) numSum += nums[i];
        }

        return totalSum - numSum;
    }
};
