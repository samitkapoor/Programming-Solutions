/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> postorder(Node root) {
        LinkedList<Integer> result = new LinkedList<>();
        Stack<Node> visited = new Stack<>();
        
        if(root == null) return result;
        
        visited.push(root);
        
        while(!visited.isEmpty()){
            Node node = visited.pop();
            result.addFirst(node.val);
            
            for(int i=0 ; i<node.children.size() ; i++){
                visited.push(node.children.get(i));
            }
        }
        
        return result;
    }
}