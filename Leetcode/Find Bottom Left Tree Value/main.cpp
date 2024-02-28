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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        int height = 1;
        int answer = root->val;

        while(!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            if(height < p.second) {
                height = p.second;
                answer = p.first->val;
            }

            if(p.first->left != nullptr) {
                q.push({p.first->left, height+1});
            }
            if(p.first->right != nullptr) {
                q.push({p.first->right, height+1});
            }
        }

        return answer;
    }
};
