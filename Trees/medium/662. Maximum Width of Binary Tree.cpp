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
    using ull = unsigned long long;
    using pp = pair<TreeNode *, ull>;

public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int maxWidth = 0;
        queue<pp> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();

            ull minn = q.front().second;
            ull first = 0, last = 0;

            for (int i = 0; i < size; i++)
            {
                pp top = q.front();
                q.pop();

                ull curr = top.second - minn;

                if (i == 0)
                    first = curr;
                if (i == size - 1)
                    last = curr;

                if (top.first->left)
                    q.push({top.first->left, curr * 2 + 1});

                if (top.first->right)
                    q.push({top.first->right, curr * 2 + 2});
            }

            maxWidth = max(maxWidth, (int)(last - first + 1));
        }

        return maxWidth;
    }
};