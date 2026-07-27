#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int findHeightLeft(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + findHeightLeft(root->left);
    }

    int findHeightRight(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + findHeightRight(root->right);
    }

    int find(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = findHeightLeft(root->left);
        int rh = findHeightRight(root->right);

        if (lh == rh)
        {
            return (1 << (lh + 1)) - 1;
        }

        return 1 + find(root->left) + find(root->right);
    }

    int countNodes(TreeNode *root)
    {
        return find(root);
    }
};