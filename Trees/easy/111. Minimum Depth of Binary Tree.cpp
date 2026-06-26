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
    int minDepth(TreeNode *root)
    {
        int depth = 0;
        if (!root)
        {
            return depth;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            depth++;
            while (size--)
            {
                TreeNode *top = q.front();
                q.pop();

                if (top->left == top->right)
                {
                    return depth;
                }

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
        }

        return depth;
    }
};