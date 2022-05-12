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
    int answer = 0;

    void traverse(TreeNode *root, int depth)
    {
        if (root == nullptr)
            return;
        if (root->right == nullptr && root->left == nullptr)
        {
            answer = max(answer, depth);
            return;
        }

        traverse(root->right, depth + 1);
        traverse(root->left, depth + 1);
    }

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        traverse(root, 1);

        return answer;
    }
};