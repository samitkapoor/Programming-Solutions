class Solution {
public:
    void swap(vector<int>& v, int i, int j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;

        return;
    }

    void findPerms(vector<vector<int>>& result, vector<int> curr, int index) {
        if(index == curr.size()) {
            result.push_back(curr);
            return;
        }

        for(int i = index ; i < curr.size() ; i++){
            swap(curr, index, i);
            findPerms(result, curr, index + 1);
            swap(curr, index, i);
        }
    }   

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        findPerms(result, nums, 0);    

        return result;
    }
};
