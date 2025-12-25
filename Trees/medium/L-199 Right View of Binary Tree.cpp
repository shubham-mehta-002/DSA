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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(!root)   return res;
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            int val = INT_MAX;
            while(size--){
                TreeNode* top = q.front();
                val = top->val;
                q.pop();
                if(top->left) {
                    q.push(top->left);
                }
                if(top->right) {
                    q.push(top->right);
                }
            }
            res.push_back(val);
            level++;
        }

        return res;
    }
};