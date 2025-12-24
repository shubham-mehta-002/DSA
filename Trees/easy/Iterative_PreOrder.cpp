
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
    stack<TreeNode*>s;
    vector<int>res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)   return res;
        s.push(root);
        while(!s.empty()){
            TreeNode* top = s.top();
            res.push_back(top->val);
            s.pop();
            if(top->right){
                s.push(top->right);
            }
            if(top->left){
                s.push(top->left);
            }
        }

        return res;
    }
};