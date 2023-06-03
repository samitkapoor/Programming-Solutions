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
    int check(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int lh = check(root->left);
        if(lh == -1) return -1;
        int rh = check(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int x = check(root);

        if(x == -1) return false;
        return true;
    }
};
