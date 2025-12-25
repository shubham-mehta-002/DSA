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
    bool check(TreeNode*p1 , TreeNode* p2){
        if(p1 == p2){
            return true;
        }
        if(!(p1 && p2)){
            return false;
        }
        return (p1->val == p2->val && check(p1->left, p2->right) && check(p1->right , p2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return true;
        }

        if(!(root->left && root->right)){
            return false;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        return check(left,right);
    }
};