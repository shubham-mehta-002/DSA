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
    int val;
public:
    int inOrder(TreeNode* root, int &k){
        if(!root){
            return -1;
        }

        int l= inOrder(root->left,k);
        if(l != -1){
            return l;
        }
        //considering root;
        k--;
        if(k==0){
            return root->val;
        }


        int r = inOrder(root->right,k);
        if(r != -1){
            return r;
        }

        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inOrder(root,k);
        // return val;
    }
};