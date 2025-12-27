#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void traverse(Node* root, vector<vector<int>>&res, vector<int>&path){
        path.push_back(root->data);
        
        if(root->left == NULL && root->right == NULL){
            vector<int>newPath(path);
            res.push_back(newPath);
        }
        
        if(root->left){
            traverse(root->left,res,path);
        }
        
        if(root->right){
            traverse(root->right,res,path);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>res;
        if(!root){
            return res;
        }
        vector<int>path;
        
        traverse(root,res,path);
        
        return res;
    }
};