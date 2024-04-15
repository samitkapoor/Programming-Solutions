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
    int dfs(TreeNode* root, int curr = 0) {
        int temp = 0;
        if(curr == 0) temp = root->val;
        else temp = (curr * 10) + root->val;

        if(root->left == nullptr && root->right == nullptr) {
            return temp;
        }

        int left, right;
        left = right = 0;
        if(root->left != nullptr) {
            left = dfs(root->left, temp);
        } 
        if(root->right != nullptr) {
            right = dfs(root->right, temp);
        }

        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root);
    }
};
