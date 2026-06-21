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

typedef long long ll;
class Solution
{
    unordered_map<ll, int> prefixSum;

public:
    int solve(TreeNode *root, ll sum, int target)
    {
        if (!root)
            return 0;

        int res = 0;
        sum += root->val;

        if (sum == target)
        {
            res += 1;
        }

        ll diff = sum - target;
        if (prefixSum.find(diff) != prefixSum.end())
        {
            res += prefixSum[diff];
        }

        prefixSum[sum]++;

        res += solve(root->left, sum, target);
        res += solve(root->right, sum, target);

        prefixSum[sum]--;
        if (prefixSum[sum] == 0)
        {
            prefixSum.erase(sum);
        }

        return res;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        return solve(root, 0, targetSum);
    }
};