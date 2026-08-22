
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
    bool find(TreeNode *root, int target)
    {
        if (!root)
            return false;

        target -= root->val;

        if (root->left == root->right)
        {
            return target == 0;
        }

        return (
            find(root->left, target) ||
            find(root->right, target));
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return find(root, targetSum);
    }
};