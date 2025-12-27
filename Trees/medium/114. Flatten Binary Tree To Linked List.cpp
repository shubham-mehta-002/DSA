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
    TreeNode* findMaxRight(TreeNode*root){
        while(root && root->right){
            root=  root->right;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr -> left){
                TreeNode* temp = findMaxRight(curr->left);
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};