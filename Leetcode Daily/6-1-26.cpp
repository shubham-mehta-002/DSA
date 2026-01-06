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
    int maxLevelSum(TreeNode* root) {
        if(!root)   return 0;
        int level = 0;
        int maxSum = INT_MIN;
        int maxSumLevel = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            level++;
            int sum = 0;
            while(size--){
                TreeNode* top = q.front();
                sum+=top->val;
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
                q.pop();
            }
            if(sum > maxSum){
                maxSum = sum;
                maxSumLevel = level;
            }
        }
        return maxSumLevel;
    }
};