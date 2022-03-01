#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*
    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    map<int, pair<int, int>> m;

    void traverse(int level, Node *root, int height)
    {
        if (root == nullptr)
        {
            return;
        }

        if (m.find(level) == m.end())
        {
            m[level] = make_pair(root->data, height);
        }
        else if (m[level].second > height)
        {
            m[level] = make_pair(root->data, height);
        }

        traverse(level - 1, root->left, height + 1);
        traverse(level + 1, root->right, height + 1);
    }

    void topView(Node *root)
    {

        traverse(0, root, 0);

        for (auto p : m)
        {
            cout << p.second.first << " ";
        }
    }

}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);

    return 0;
}
