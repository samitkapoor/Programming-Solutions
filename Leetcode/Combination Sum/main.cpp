//use the pick/non-pick strategy with recursion
class Solution {
public:
    void helper(vector<int> candidates, int index, vector<vector<int>>& result, int target, vector<int> curr){
        if(index >= candidates.size()){
          //if target is 0 that means we have found a solution that has the target equal to the initial target and that combination is stored in curr
            if(target == 0) result.push_back(curr);
            return;
        }

      // if the value of the current element of the candidates array is less than target, this means that we can pick that elements
        if(candidates[index] <= target){
            curr.push_back(candidates[index]);
            helper(candidates, index, result, target - candidates[index], curr);
          //we have picked that element, now we have to find sequences without it 
          //NON - PICK
            curr.pop_back();
        }

        helper(candidates, index+1, result, target, curr);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        helper(candidates, 0, res, target, {});

        return res;
    }
};
