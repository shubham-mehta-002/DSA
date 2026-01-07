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
    TreeNode* maxLeft(TreeNode*curr){
        while(curr->left){
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* helper(TreeNode*curr){
        if(! curr->left){
            return curr->right;
        }
        if(! curr->right){
            return curr->left;
        }

        TreeNode* temp = maxLeft(curr->right);
        temp->left = curr->left;
        curr->left = NULL;
        return curr->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        
        TreeNode* curr =root;
        TreeNode* prev = NULL;

        while(curr){
            if(curr->val > key){
                prev = curr;
                curr = curr->left;
            }else if(curr->val < key){
                prev = curr;
                curr = curr->right;
            }else{
                TreeNode* updatedTree = helper(curr);
                if(!prev){
                    return updatedTree;
                }
                if(prev->val > curr->val){
                    prev->left = updatedTree;
                }else{
                    prev->right = updatedTree;
                }
                break;
            }
        }

        return root;
    }
};