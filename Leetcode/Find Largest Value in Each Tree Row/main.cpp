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
    vector<int> result;
    
    void fun(TreeNode* root, int depth){
        if(root == nullptr) return;
        
        if(depth == ((int)result.size())){
            result.push_back(root->val);
        }
        else if(result[depth] < root->val){
            result[depth] = root->val;
        }
        
        fun(root->left, depth+1);
        fun(root->right, depth+1);
        
    }
    
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return result;
        
        fun(root, 0);
        
        return result;
    }
};
