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
    void pushLeft(TreeNode*root,stack<TreeNode*>&s){
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode* curr = root;
        stack<TreeNode*>s;

        pushLeft(root,s);

        while(!s.empty()){
            TreeNode* top = s.top();
            s.pop();
            res.push_back(top->val);
            pushLeft(top->right,s);
        }

        return res;
    }
};