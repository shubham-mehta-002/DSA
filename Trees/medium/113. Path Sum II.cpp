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
    vector<vector<int>> res;

public:
    void find(TreeNode *root, int sum, vector<int> &nodes, int targetSum)
    {
        if (root == NULL)
            return;

        nodes.push_back(root->val);

        if (!root->left && !root->right && (targetSum == sum + root->val))
        {
            res.push_back(nodes);
        }

        find(root->left, sum + root->val, nodes, targetSum);
        find(root->right, sum + root->val, nodes, targetSum);

        nodes.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> nodes;
        find(root, 0, nodes, targetSum);
        return res;
    }
};