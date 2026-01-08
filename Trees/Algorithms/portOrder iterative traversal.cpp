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
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr || !s.empty()) {
        if (curr) {
            s.push(curr);
            curr = curr->left;
        } else {
            TreeNode* node = s.top();
            if (node->right && lastVisited != node->right) {
                curr = node->right;
            } else {
                res.push_back(node->val);
                lastVisited = node;
                s.pop();
            }
        }
    }
    return res;
}

};