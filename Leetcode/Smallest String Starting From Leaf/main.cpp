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
    string smaller(string& a, string& b) {
        if(a == "") 
            return b;
        if(b == "") 
            return a;

        int i = 0;

        while(i < a.length() && b.length()) {
            if(a[i] < b[i])
                return a;
            else if(a[i] > b[i])
                return b;
            i++;
        }

        return a.length() < b.length() ? a : b;
    }

    string smallest(TreeNode* root, string& word) {
        if(root == nullptr) return "";

        string left = "", right = "";
        string temp(1, (char)(root->val + 'a'));
        string newWord = temp + word;

        if(root->left == nullptr && root->right == nullptr) 
            return newWord;

        if(root->left != nullptr)
            left = smallest(root->left, newWord);
        if(root->right != nullptr)
            right = smallest(root->right, newWord);

        if(left == "") 
            return right;
        else if(right == "") 
            return left;

        return smaller(left, right);
    }

    string smallestFromLeaf(TreeNode* root) {
        if(root == nullptr) 
            return "";
        string s = "";

        return smallest(root, s);
    }
};
