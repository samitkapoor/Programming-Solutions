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
    List<Integer> result = new ArrayList<Integer>();
    
    public void helperFunction(TreeNode root, int depth){
        if(root == null) return;
        
        if(result.size() == depth){
            result.add(root.val);
        }
        else if(result.get(depth) < root.val){
            result.set(depth, root.val);
        }
        
        helperFunction(root.left, depth+1);
        helperFunction(root.right, depth+1);
    }
    
    public List<Integer> largestValues(TreeNode root) {
        if(root == null) return result;
        
        helperFunction(root, 0);
        
        return result;
    }
}
