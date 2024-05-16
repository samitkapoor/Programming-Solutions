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
    bool evaluateTree(TreeNode* root) {
        if(root->val <= 1) return root->val == 1;
        stack<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.top();

            if(curr->right->val > 1) {
                q.push(curr->right);
            } 
            if(curr->left->val > 1) {
                q.push(curr->left);
            }

            if(curr->left->val <= 1 && curr->right->val <= 1) {
                if(curr->val == 2) {
                    curr->val = curr->left->val | curr->right->val;
                } else {
                    curr->val = curr->left->val & curr->right->val;
                }

                q.pop();
            }
        }

        return root->val == 1;
    }
};

/* 
   2
 1   3 //0
n n 0 1
*/
