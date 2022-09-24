/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;

        findPaths(root, targetSum, {}, result);
        
        return result;
    }
    
    void findPaths(TreeNode* root, int targetSum, vector<int> current, vector<vector<int>>& result){
        if(root == nullptr){
            return;
        }
        
        current.push_back(root->val);
        if(targetSum == root->val && root->left == nullptr && root->right == nullptr){
            result.push_back(current);
            return;
        }
        
        findPaths(root->left, targetSum - root->val, vector<int>(current.begin(), current.end()), result);
        findPaths(root->right, targetSum - root->val, vector<int>(current.begin(), current.end()), result);
    }
    
};
