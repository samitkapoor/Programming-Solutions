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
    void help(string& s, TreeNode* root){
        s += to_string(root->val);
        
        if(root->left != nullptr){
            s += "(";
            help(s, root->left);
            s += ")";
        } else if(root->left == nullptr && root->right != nullptr) {
            s+= "()";
        }
        
        if(root->right != nullptr){
            s += "(";
            help(s, root->right);
            s += ")";
        }        
    }
    
    string tree2str(TreeNode* root) {
        string result = "";
        
        if(root == nullptr){
            return result;
        }
        
        help(result, root);
        
        return result;
    }
};
