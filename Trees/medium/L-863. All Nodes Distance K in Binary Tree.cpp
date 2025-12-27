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
    void traverse(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m, TreeNode*parent){
        if(!root){
            return;
        }

        m[root] = parent;
        traverse(root->left,m,root);
        traverse(root->right,m,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        if(!root)   return res;
        if(k==0){
            res.push_back(target->val);
            return res;
        } 

        unordered_map<TreeNode*,TreeNode*>m;
        unordered_map<TreeNode*,int>vis;

        traverse(root,m,NULL);

        queue<TreeNode*>q;
        q.push(target);

        while(k--){
            int size = q.size();
            while(size--){
                TreeNode*top = q.front();
                q.pop();
                vis[top] = 1;
                
                if(top->left && !vis[top->left]) q.push(top->left);
                if(top->right && !vis[top->right]) q.push(top->right);
                if(m[top] && !vis[m[top]]) q.push(m[top]);
            }
        }

        while(!q.empty()){
            res.push_back((q.front())->val);
            q.pop();
        }

        return res;
    }
};