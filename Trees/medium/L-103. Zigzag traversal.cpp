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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        vector<vector<int>>res;
        if(!root)   return res;
        s1.push(root);
        bool leftToRight = true;

        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                int size = s1.size();
                vector<int>level;
                while(size--){
                    TreeNode* top = s1.top();
                    level.push_back(top->val);
                    s1.pop();

                    if(leftToRight){
                        if(top->left) s2.push(top->left);
                        if(top->right) s2.push(top->right);
                    }else{
                        if(top->right) s2.push(top->right);
                        if(top->left) s2.push(top->left);
                    }
                }
                // if(s1.empty()){
                    leftToRight = !leftToRight; 
                    res.push_back(level);
                // }
            }



            while(!s2.empty()){
                int size = s2.size();
                vector<int>level;
                while(size--){
                    TreeNode* top = s2.top();
                    level.push_back(top->val);
                    s2.pop();

                    if(leftToRight){
                        if(top->left) s1.push(top->left);
                        if(top->right) s1.push(top->right);
                    }else{
                        if(top->right) s1.push(top->right);
                        if(top->left) s1.push(top->left);
                    }
                }
                // if(s2.empty()){
                    leftToRight = !leftToRight;
                    res.push_back(level);
                // }
            }
        }

        return res;

    }
};