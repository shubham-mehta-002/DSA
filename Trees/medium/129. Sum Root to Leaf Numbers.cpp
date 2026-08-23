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
    const long MOD = (long)INT_MAX + 1;

public:
    int find(TreeNode *root, int curr)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return (curr * 10 + root->val);
        }

        long res = 0;

        if (root->left)
        {
            res += (find(root->left, curr * 10 + root->val) % MOD);
        }

        if (root->right)
        {
            res += (find(root->right, curr * 10 + root->val) % MOD);
        }

        return res % MOD;
    }
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        return find(root, 0) % MOD;
    }
};