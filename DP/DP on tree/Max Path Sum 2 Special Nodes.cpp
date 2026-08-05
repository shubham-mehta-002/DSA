#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    int find(Node *root, int &maxx)
    {
        if (!root)
            return INT_MIN;

        if (!root->left && !root->right)
        {
            return root->data;
        }

        int left = find(root->left, maxx);
        int right = find(root->right, maxx);

        if (root->left && root->right)
        {
            maxx = max(maxx, left + right + root->data);
        }

        return (max(left, right) + root->data);
    }

    int maxPathSum(Node *root)
    {

        int maxx = INT_MIN;
        int temp = find(root, maxx);

        if (!root->left || !root->right)
        {
            maxx = max(maxx, temp);
        }

        return maxx;
    }
};