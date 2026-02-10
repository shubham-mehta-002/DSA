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
    void getNodes(TreeNode *root, vector<int> &nodes)
    {
        if (!root)
            return;
        getNodes(root->left, nodes);
        nodes.push_back(root->val);
        getNodes(root->right, nodes);
    }

    TreeNode *buildTree(vector<int> &nodes, int low, int high)
    {
        if (low == high)
        {
            return new TreeNode(nodes[low]);
        }

        int mid = low + (high - low) / 2;
        TreeNode *root = new TreeNode(nodes[mid]);
        if (mid > low)
            root->left = buildTree(nodes, low, mid - 1);
        if (mid < high)
            root->right = buildTree(nodes, mid + 1, high);

        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nodes;
        getNodes(root, nodes);
        return buildTree(nodes, 0, nodes.size() - 1);
    }
};