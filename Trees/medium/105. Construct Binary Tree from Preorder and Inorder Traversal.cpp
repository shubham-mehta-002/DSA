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

public:
    TreeNode *build(int &index, int left, int right, vector<int> &preorder, vector<int> &inorder)
    {
        int idx = mpp[preorder[index]];

        TreeNode *root = new TreeNode(preorder[index]);

        if (idx - 1 >= left)
        {
            index++;
            root->left = build(index, left, idx - 1, preorder, inorder);
        }
        if (idx + 1 <= right)
        {
            index++;
            root->right = build(index, idx + 1, right, preorder, inorder);
        }

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        int index = 0;
        return build(index, 0, inorder.size() - 1, preorder, inorder);
    }
};