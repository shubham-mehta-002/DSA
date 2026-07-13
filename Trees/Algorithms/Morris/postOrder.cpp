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
    TreeNode *findSuccessor(TreeNode *node)
    {
        TreeNode *temp = node->right;

        while (temp->left && temp->left != node)
        {
            temp = temp->left;
        }

        return temp;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->right)
            {
                TreeNode *succ = findSuccessor(curr);

                if (succ->left == curr)
                {
                    succ->left = NULL;
                    curr = curr->left;
                }
                else
                {
                    res.push_back(curr->val);
                    succ->left = curr;
                    curr = curr->right;
                }
            }
            else
            {
                res.push_back(curr->val);
                curr = curr->left;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};