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
    void inorder(TreeNode* root, vector<TreeNode*> &unsorted){
        if(!root)   return;
        inorder(root->left, unsorted);
        unsorted.push_back(root);
        inorder(root->right, unsorted);
    }
   
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> unsorted;
        inorder(root,unsorted);
        vector<TreeNode*> sorted(unsorted.begin(), unsorted.end());
        sort(sorted.begin(),sorted.end(),[](TreeNode*a, TreeNode*b){
            return a->val < b->val;
        });

        TreeNode*a=NULL, *b = NULL;

        for(int i=0;i<unsorted.size();i++){
            if(unsorted[i] != sorted[i]){
                if(a == NULL){
                    a = unsorted[i];
                }else{
                    b = unsorted[i];
                }
            }    
        }

        // swap
        int temp = a->val;
        a->val = b->val;
        b->val = temp;

    }
};