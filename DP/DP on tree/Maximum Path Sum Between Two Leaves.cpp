#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

long long find(TreeNode<int> *root, long long &maxx)
{
    if (root == NULL)
    {
        return 0;
    }

    long long leftMax = find(root->left, maxx);
    long long rightMax = find(root->right, maxx);
    if (root->left && root->right)
    {
        maxx = max(maxx, leftMax + rightMax + root->val);
    }

    return max(leftMax, rightMax) + root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    long long maxx = LLONG_MIN;
    find(root, maxx);
    return maxx == LLONG_MIN ? -1 : maxx;
}