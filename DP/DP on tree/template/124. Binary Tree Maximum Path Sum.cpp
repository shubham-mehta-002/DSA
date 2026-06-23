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
    int maxx = INT_MIN;

public:
    int find(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftMax = find(root->left);
        leftMax = max(leftMax, 0);

        int rightMax = find(root->right);
        rightMax = max(rightMax, 0);

        maxx = max({maxx, leftMax + rightMax + root->val});

        return max(leftMax, rightMax) + root->val;
    }
    int maxPathSum(TreeNode *root)
    {
        find(root);
        return maxx;
    }
};