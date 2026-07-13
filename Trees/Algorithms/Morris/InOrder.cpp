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
    TreeNode *findPredecessor(TreeNode *node)
    {
        TreeNode *temp = node->left;

        while (temp->right && temp->right != node)
        {
            temp = temp->right;
        }

        return temp;
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *pred = findPredecessor(curr);

                // already temporary link is created
                if (pred->right == curr)
                {
                    pred->right = NULL;

                    res.push_back(curr->val);
                    curr = curr->right;
                }
                else
                {
                    // create temp link
                    pred->right = curr;
                    curr = curr->left;
                }
            }
            else
            {
                res.push_back(curr->val);
                curr = curr->right;
            }
        }

        return res;
    }
};