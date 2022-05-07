// iterative solution to the problem
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> traversal;
        vector<int> result;

        if (root == nullptr)
            return result;

        TreeNode *curr = root;

        while (curr != nullptr || !traversal.empty())
        {
            while (curr != nullptr)
            {
                traversal.push(curr);
                curr = curr->left;
            }

            curr = traversal.top();
            traversal.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }

        return result;
    }
};