class Solution {
public:
    void findSubsets(int index, vector<vector<int>>& result, vector<int> ds, vector<int> nums){
        if(index == nums.size()){
            result.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        findSubsets(index + 1, result, ds, nums);
        ds.pop_back();
        while(( index + 1 < nums.size() )&&( nums[index] == nums[index+1] )) {
            index+=1;
        }
        findSubsets(index + 1, result,ds ,nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, result, ds, nums);

        return result;
    }
};
