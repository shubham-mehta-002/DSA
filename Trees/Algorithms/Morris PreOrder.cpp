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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode* curr = root;
        while(!root){
            return res;
        }

        while(curr){
            res.push_back(curr->val);
            if(curr->left){
                TreeNode* temp = findMaxRight(curr->left);
                temp->right = curr->right;
                curr->right = NULL;
                curr = curr->left;
            }else{
                TreeNode* prev = curr;
                curr = curr->right;
                prev->right=NULL;
            }
        }

        return res;
    }
};