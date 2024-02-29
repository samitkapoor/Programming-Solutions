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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        while(!q.empty()) {
            int size = q.size();
            int prev = height % 2 == 0 ? INT_MIN: INT_MAX;
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();

                if((height % 2 == 0 && ((curr->val % 2 == 0) || (curr->val <= prev))) || (height % 2 != 0 && ((curr->val % 2 != 0) || (curr->val >= prev)))) {
                    cout<<curr->val<<endl;
                    return false;
                }

                prev = curr->val;
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }

            height++;
        }

        return true;
    }
};
