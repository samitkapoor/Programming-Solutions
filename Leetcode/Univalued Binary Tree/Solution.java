/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static int val;
    
    static boolean traverse(TreeNode root){
        if(root == null) return true;
        
        if(root.val != val) return false;
        
        return true && traverse(root.left) && traverse(root.right);
    }
    
    public boolean isUnivalTree(TreeNode root) {
        if(root == null) {
            return true;
        }
        
        val = root.val;
        
        return traverse(root);
    }
}
