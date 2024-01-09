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
    vector<int> getPath(TreeNode* root) {
        vector<int> path;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) { 
            TreeNode* temp = st.top();
            st.pop();

            if(temp -> left == nullptr && temp -> right == nullptr) {
                path.push_back(temp->val);
            }
            if(temp -> left != nullptr) {
                st.push(temp->left);
            }
            if(temp -> right != nullptr) {
                st.push(temp->right);
            }
        }

        return path;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 != nullptr) return false;
        if(root2 == nullptr && root1 != nullptr) return false;

        vector<int> path1 = getPath(root1);
        vector<int> path2 = getPath(root2);

        if(path1.size() != path2.size()) return false;
        for(int i = 0 ; i < path1.size() ; i++){
            if(path1[i] != path2[i]) return false;
        }

        return true;
    }
};
