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
public:
    bool check(TreeNode* root, long long minVal,long long maxVal){
        if(!root){
            return true;
        }

        return (
            minVal < root->val && root->val < maxVal && 
            check(root->left, minVal , root->val)  &&
            check(root->right, root->val, maxVal)
        );
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};