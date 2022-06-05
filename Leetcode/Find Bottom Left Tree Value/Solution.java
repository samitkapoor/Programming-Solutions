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
    public int findBottomLeftValue(TreeNode root) {
        if(root == null) return 0;
        
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);
        
        while(!queue.isEmpty()){
            root = queue.poll();
            
            if(root.right != null) queue.offer(root.right);
            if(root.left != null) queue.offer(root.left);
        }
        
        return root.val;
    }
}
