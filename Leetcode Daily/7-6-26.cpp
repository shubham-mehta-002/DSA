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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> mpp;
        unordered_map<int, int> poosibleRoot;

        for (auto d : descriptions)
        {
            int parent = d[0];
            int child = d[1];
            bool isLeft = d[2];

            if (poosibleRoot[parent] != -1)
            {
                poosibleRoot[parent] = 1;
            }

            poosibleRoot[child] = -1;

            if (mpp.find(child) != mpp.end())
                mpp[child] = new TreeNode(child);
            if (mpp.find(parent) != mpp.end())
                mpp[parent] = new TreeNode(parent);

            if (isLeft)
            {
                mpp[parent]->left = mpp[child];
            }
            else
            {
                mpp[parent]->right = mpp[child];
            }
        }

        int root;
        for (auto m : poosibleRoot)
        {
            if (m.second == 1)
            {
                root = m.first;
                break;
            }
        }
        return mpp[root];
    }
};