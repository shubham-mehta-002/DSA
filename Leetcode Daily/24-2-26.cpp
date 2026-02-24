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
    void find(TreeNode *root, int &sum, int curr)
    {
        if (root == NULL)
        {
            return;
        }

        curr = curr << 1;
        curr = curr | root->val;

        if (root->left == root->right && root->left == NULL)
        {
            sum += curr;
        }
        else
        {
            find(root->left, sum, curr);
            find(root->right, sum, curr);
        }
    }
    int sumRootToLeaf(TreeNode *root)
    {
        int sum = 0;
        int curr = 0;
        find(root, sum, curr);

        return sum;
    }
};