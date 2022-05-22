/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {

    public int goDeep(TreeNode root, int depth) {
        if (root == null)
            return 0;

        if (root.left == null && root.right == null) {
            return depth;
        }

        return Math.max(goDeep(root.right, depth + 1), goDeep(root.left, depth + 1));
    }

    public int maxDepth(TreeNode root) {
        int result = goDeep(root, 1);

        return result;
    }
}