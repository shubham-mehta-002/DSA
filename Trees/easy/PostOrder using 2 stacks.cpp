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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root){
            return res;
        }
        stack<TreeNode*>s1;
        stack<int>s2;
        s1.push(root);

        while(!s1.empty()){
            TreeNode* top = s1.top();
            s1.pop();

            s2.push(top->val);

            if(top->left){
                s1.push(top->left);
            }

            if(top->right){
                s1.push(top->right);
            }
        } 

        while(!s2.empty()){
            res.push_back(s2.top());
            s2.pop();
        }
        return res;
    }
};