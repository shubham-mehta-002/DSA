#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    void solve(Node *root)
    {
        if (!root || !root->left)
        {
            return;
        }

        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : NULL;

        solve(root->left);
        solve(root->right);
    }
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        root->next = NULL;

        solve(root);

        return root;
    }
};