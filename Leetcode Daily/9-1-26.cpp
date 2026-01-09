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
    TreeNode* findLCA(TreeNode* root,int currentDepth, int maxDepth){
        if(!root){
            return NULL;
        }

        if(currentDepth == maxDepth){
            return root;
        }

        TreeNode* left = findLCA(root->left, currentDepth+1, maxDepth);
        TreeNode* right = findLCA(root->right, currentDepth+1, maxDepth);

        if(left && right){
            return root;
        }

        return left ? left : right;
    }

    int findLevel(TreeNode* root){
        int level = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            level++;
            while(size--){
                TreeNode* top = q.front();
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
                q.pop();
            }
        }

        return level-1;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = findLevel(root);
    
        return findLCA(root,0,maxDepth);
    }
};