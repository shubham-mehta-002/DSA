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
    unordered_map<int, int> mpp;
    int postIndex;

public:
    TreeNode *build(int left, int right, vector<int> &inorder, vector<int> &postorder)
    {
        if (left > right || postIndex < 0)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[postIndex]);
        int idx = mpp[postorder[postIndex]];
        postIndex--;

        root->right = build(idx + 1, right, inorder, postorder);
        root->left = build(left, idx - 1, inorder, postorder);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size();
        postIndex = n - 1;

        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        return build(0, n - 1, inorder, postorder);
    }
};