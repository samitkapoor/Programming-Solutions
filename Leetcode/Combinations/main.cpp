class Solution {
public:
    void generateCombinations(int n, int k, int s, vector<int>& v, vector<vector<int>>& result) {
        if(v.size() == k) {
            result.push_back(v);
            return;
        }

        for(int i = s ; i <= n ; i++){
            v.push_back(i);
            generateCombinations(n, k, i+1, v, result);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> result;
        generateCombinations(n, k, 1, v, result);
        return result;
    }
};
