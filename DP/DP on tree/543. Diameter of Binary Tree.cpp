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
    int maxx = 0;

public:
    int find(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = find(root->left);
        int right = find(root->right);

        maxx = max({maxx, left + right});
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        find(root);

        return maxx;
    }
};