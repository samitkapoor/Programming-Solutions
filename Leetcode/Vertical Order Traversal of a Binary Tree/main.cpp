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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> m;
        
        q.push(make_pair(0, root));
        
        while(!q.empty()){
            multiset<pair<int, int>> s;
            
            int n = q.size();
            
            for(int i=0 ; i<n ; i++){
                auto p = q.front();
                q.pop();
                
                s.insert(make_pair(p.first, p.second->val));
                
                if(p.second->left != nullptr){
                    q.push(make_pair(p.first-1, p.second->left));
                }
                if(p.second->right != nullptr){
                    q.push(make_pair(p.first+1, p.second->right));
                }
            }
            
            for(auto p : s){
                m[p.first].push_back(p.second);
            }
        }
        
        vector<vector<int>> result;
        
        for(auto p : m){
            result.push_back(p.second);
        }
        
        return result;    
    }
};
