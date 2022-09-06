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
    TreeNode* pruneTree(TreeNode* root) {
        return help(root) ? root : nullptr;
    }
    
    bool help(TreeNode* root){
        if(root == nullptr){
            return false;
        }
        
        bool left = help(root->left);
        bool right = help(root->right);
        
        if(!left){
            root->left = nullptr;
        }
        
        if(!right){
            root->right = nullptr;
        }
        
        return root->val == 1 || left || right;
    }
};
