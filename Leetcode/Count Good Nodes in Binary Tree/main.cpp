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
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
    
private:    
    int helper(TreeNode* root, int m){
        if(root == nullptr) return 0;
        
        int result = root->val >= m ? 1 : 0;
        if(result == 1){
            cout<<root->val<<endl;
        }
        m = max(m, root->val);
        
        return result + helper(root->left, m) + helper(root->right, m);
    }
};
