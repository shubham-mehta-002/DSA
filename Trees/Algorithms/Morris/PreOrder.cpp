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
    TreeNode *findPredecessor(TreeNode *node)
    {
        TreeNode *temp = node->left;

        while (temp->right && temp->right != node)
        {
            temp = temp->right;
        }

        return temp;
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *pred = findPredecessor(curr);

                // remove if already link exists
                if (pred->right == curr)
                {
                    pred->right = NULL;
                    curr = curr->right;
                }
                else
                {
                    // create new temp link
                    res.push_back(curr->val);
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