/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        stack<Node *> s;
        vector<int> result;

        if (root == NULL)
        {
            return result;
        }

        s.push(root);
        while (!s.empty())
        {
            Node *t = s.top();
            s.pop();
            result.push_back(t->val);
            for (Node *x : t->children)
            {
                s.push(x);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};