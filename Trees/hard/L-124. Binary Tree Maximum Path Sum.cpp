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
    int maxSum = INT_MIN;
public:
    int find(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftSum = find(root->left);
        leftSum = leftSum < 0 ? 0 : leftSum;
        int rightSum = find(root->right);
        rightSum = rightSum < 0 ? 0 : rightSum;
        int totalSum = leftSum + rightSum + root->val;

        maxSum = max(maxSum, totalSum);
        return (max(leftSum,rightSum)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        find(root);
        return maxSum;
    }
};