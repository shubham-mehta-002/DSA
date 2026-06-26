
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int cnt = size;
            long long sum = 0;
            while (size--)
            {
                TreeNode *top = q.front();
                q.pop();

                sum += top->val;
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }

            double avg = sum / (cnt * 1.0);
            res.push_back(avg);
        }

        return res;
    }
};