#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    const int MOD = 1000000007;
    long long maxProd = INT_MIN;
public:
    void findTotalSum(TreeNode*root, long long& total){
        if(!root)   return;
        total += root->val;
        findTotalSum(root->left,total);
        findTotalSum(root->right,total);
    }

    int findMax(TreeNode* root,long long total){
        if(!root)   return 0;
        int l = findMax(root->left,total);
        int r = findMax(root->right,total);
            
        int val = root->val + l + r;
        maxProd = max(maxProd , (total - val)*val);

        return val;
    }
    int maxProduct(TreeNode* root) {
        long long total = 0;
        findTotalSum(root,total);
        findMax(root,total);
        cout<<maxProd;
        return maxProd % MOD;
    }
};