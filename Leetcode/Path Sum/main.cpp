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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        
        stack<TreeNode*> nodes;
        stack<int> sums;
        
        nodes.push(root);
        sums.push(targetSum-(root->val));
        
        while(!nodes.empty()){
            TreeNode *current = nodes.top();
            nodes.pop();
            
            int currentSum = sums.top();
            sums.pop();
            
            if(current->right == nullptr && current->left == nullptr && currentSum == 0){
                return true;
            }
            
            if(current->left != nullptr){
                nodes.push(current->left);
                sums.push(currentSum - current->left->val);
            }
            
            if(current->right != nullptr){
                nodes.push(current->right);
                sums.push(currentSum - current->right->val);
            }
        }
        
        return false;
    }
};