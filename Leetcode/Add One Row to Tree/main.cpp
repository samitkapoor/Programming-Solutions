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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr) return new TreeNode(val);
        else if(depth == 1) {
            TreeNode* newHead = new TreeNode(val);
            newHead->left = root;
            return newHead;
        }

        queue<TreeNode*> q;
        q.push(root);

        int _depth = 1;
        while(!q.empty()) {
            if(_depth == depth - 1) {
                int n = q.size();
                while(n != 0) {
                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* left = node->left;
                    TreeNode* right = node->right;

                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);

                    node->left->left = left;
                    node->right->right = right;

                    n--;
                }
            } else {
                int n = q.size();
                while(n != 0) {
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left != nullptr) {
                        q.push(node->left);
                    } 
                    if(node->right != nullptr) {
                        q.push(node->right);
                    }
                    n--;
                }
            }
            _depth++;
        }

        return root;
    }
};
