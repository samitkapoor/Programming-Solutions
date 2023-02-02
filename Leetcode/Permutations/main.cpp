class Solution {
public:
    void findPermutations(vector<vector<int>>&result, vector<int> curr, vector<int> bits, vector<int> nums){
        if(curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }

        for(int i=0 ; i<bits.size() ; i++){
            if(bits[i] == 0){
                curr.push_back(nums[i]);
                bits[i] = 1;
                findPermutations(result, curr, bits, nums);
                curr.pop_back();
                bits[i] = 0;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<int> bits(nums.size(), 0);

        findPermutations(result, curr, bits, nums);

        return result;
    }
};
