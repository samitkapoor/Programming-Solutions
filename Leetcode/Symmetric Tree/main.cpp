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
    
    bool mirror(TreeNode* a, TreeNode* b){
        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr || b == nullptr) return false;
        
        return (a->val == b->val) && mirror(a->left, b->right) && mirror(a->right, b->left);   
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        
        return mirror(root, root);
    }
};