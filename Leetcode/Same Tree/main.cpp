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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()) {
            TreeNode* t1 = q1.front();
            q1.pop();
            TreeNode* t2 = q2.front();
            q2.pop();

            if(t1 != nullptr && t2 != nullptr && t1->val != t2->val) return false;
            if((t1 != nullptr && t2 == nullptr) || (t1 == nullptr && t2 != nullptr)) return false;

            if(t1 != nullptr) {
                q1.push(t1->left);
                q1.push(t1->right);
            }
            if(t2 != nullptr) {
                q2.push(t2->left);
                q2.push(t2->right);
            }
        }

        return q1.empty() == q2.empty();
    }
};
