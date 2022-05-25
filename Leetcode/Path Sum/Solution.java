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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        
        Stack<TreeNode> nodes = new Stack();
        Stack<Integer> sums = new Stack();
        
        nodes.push(root);
        sums.push(targetSum - root.val);
        
        while(!nodes.isEmpty()){
            TreeNode currentNode = nodes.pop();
            int currentSum = sums.pop();
            
            if(currentNode.left == null && currentNode.right == null && currentSum == 0){
                return true;
            }
            
            if(currentNode.left!=null){
                nodes.push(currentNode.left);
                sums.push(currentSum - currentNode.left.val);
            }
            
            if(currentNode.right != null){
                nodes.push(currentNode.right);
                sums.push(currentSum - currentNode.right.val);
            }            
        }
        
        return false;
    }
}