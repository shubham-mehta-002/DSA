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
    unordered_map<int,int>m;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }

        bool left = findTarget(root->left,k);
        if(left)    return true;

        if(m[k-root->val] == 1){
            return true;
        }
        m[root->val] = 1;

        bool right = findTarget(root->right,k);
        if(right)   return true;

        return false;
    }
};