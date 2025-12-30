//https://www.interviewbit.com/problems/path-to-given-node/
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
bool preOrder(TreeNode* root, int B, vector<int>&path){
    if(!root)   return false;
    path.push_back(root->val);
    if(root->val == B){
        return true;
    }    
   
    if(preOrder(root->left,B,path)) return true;
    if(preOrder(root->right,B,path)) return true;
    
    path.pop_back();
   
    return false;
}

vector<int> solve(TreeNode* A, int B) {
    vector<int>path;
    preOrder(A,B,path);
    return path;
}
