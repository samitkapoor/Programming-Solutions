import java.util.*;

class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    LinkedList<Integer> result = new LinkedList<>();

    void traverse(TreeNode root) {
        if (root == null)
            return;

        traverse(root.left);
        result.add(root.val);
        traverse(root.right);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        traverse(root);

        return result;
    }
}