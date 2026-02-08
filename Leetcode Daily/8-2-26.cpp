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
    int find(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = find(root->left);
        int right = find(root->right);

        if (left == -1 || right == -1 || abs(left - right) > 1)
        {
            return -1;
        }

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return find(root) != -1;
    }
};