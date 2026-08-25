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
    int find(TreeNode *root, int maxx)
    {
        if (!root)
        {
            return 0;
        }

        int res = 0;
        if (root->val >= maxx)
        {
            maxx = root->val;
            res++;
        }

        res += find(root->left, maxx);
        res += find(root->right, maxx);

        return res;
    }

    int goodNodes(TreeNode *root)
    {
        return find(root, INT_MIN);
    }
};