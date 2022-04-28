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
class Solution
{
public:
    vector<int> traversal;

    void traversalInorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        traversalInorder(root->left);
        traversal.push_back(root->val);
        traversalInorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        traversalInorder(root);
        return traversal;
    }
};