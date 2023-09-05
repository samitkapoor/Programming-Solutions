class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> complements;
        for(int i = 0 ; i < nums.size() ; i++){
            if(complements[nums[i]] != 0) {
                return {complements[nums[i]]-1, i};
            } else {
                complements[target-nums[i]] = i+1;
            }
        }

        return {-1, -1};
    }
};
