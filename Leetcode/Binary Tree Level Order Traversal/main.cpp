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
    
    int levels = 0;       
    
    void countLevels(TreeNode* root, int l){
        if(root==nullptr) return;
        
        if(l > levels) levels = l; 
        
        countLevels(root->left, l+1);
        countLevels(root->right,l+1);
    }
    
    void traverse(TreeNode* root, int l, vector<vector<int>>& nodes){
        if(root == nullptr) return;
        
        nodes[l-1].push_back(root->val);
        
        traverse(root->left, l+1, nodes);
        traverse(root->right, l+1, nodes);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {        
        countLevels(root, 1);
        
        vector<vector<int>> nodes(levels);
        
        traverse(root, 1, nodes);
        
        return nodes;
        
    }
};
