#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int find(Node *root)
    {
        if (!root)
            return 0;
        int left = find(root->left);
        int right = find(root->right);

        return 1 + left + right;
    }
    int getSize(Node *root)
    {
        return find(root);
    }
};