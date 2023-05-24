class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<TreeNode*> curr;
        curr.push(root);
        while(!curr.empty()) {
            queue<TreeNode*> temp;
            vector<int> currLevel;
            while(!curr.empty()) {
                TreeNode* front = curr.front();
                currLevel.push_back(front->val);
                if(front->left != nullptr) {
                    temp.push(front->left);
                }
                if(front->right != nullptr) {
                    temp.push(front->right);
                }

                curr.pop();
            }
            result.push_back(currLevel);
            curr = temp;
        }

        return result;
    }
};
