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
    int dfs(TreeNode* root, int& moves) {
        if(root == nullptr) return 0;

        int leftCoins = dfs(root->left, moves);
        int rightCoins = dfs(root->right, moves);

        moves += abs(leftCoins) + abs(rightCoins);

        return root->val - 1 + leftCoins + rightCoins;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};
