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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        queue<TreeNode*> temp;
        
        double sum, count;
        sum = count = 0;
        
        while(!q.empty() || !temp.empty()){
            TreeNode* t = q.front();
            q.pop();
            
            if(t->left != NULL)            
                temp.push(t->left);
            if(t->right != NULL)    
                temp.push(t->right);
            
            sum += t->val;
            count++;
            
            if(q.empty()){
                q = temp;
                temp = {};
                
                result.push_back(sum/count);
                
                count = 0;
                sum = 0;
            }
        }
        
        return result;
    }
};
