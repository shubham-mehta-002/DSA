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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        int level = 0;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            bool isOdd = (level % 2);
            int prev = isOdd ? INT_MAX : -1;

            while (size--)
            {
                TreeNode *top = q.front();
                q.pop();

                int val = top->val;

                if (isOdd && (prev <= val || val % 2 == 1))
                    return false;
                if (!isOdd && (prev >= val || val % 2 == 0))
                    return false;

                prev = val;

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            level++;
        }

        return true;
    }
};