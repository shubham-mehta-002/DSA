#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int data) {
        data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    bool isLeaf(Node* root){
        return root && root->left == root->right;
    }
    
    void findLeft(Node*root, vector<int>&res){
        Node*temp = root;
        while(temp){
            if(isLeaf(temp)){
                return;
            }
            res.push_back(temp->data);
            if(temp->left){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
    }
    
    void findRight(Node*root,vector<int>&res){
        stack<Node*>st;
        Node*curr = root;
        while(curr && !isLeaf(curr)){
            st.push(curr);
            if(curr->right)  {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        
        while(!st.empty()){
            res.push_back(st.top()->data);
            st.pop();
        }
    }
    
    void findLeaf(Node* root, vector<int>&res){
        if(!root)   return;
        findLeaf(root->left,res);
        if(isLeaf(root)){
            res.push_back(root->data);
        }
        findLeaf(root->right,res);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(!isLeaf(root)) res.push_back(root->data);
        findLeft(root->left,res);
        findLeaf(root,res);
        findRight(root->right,res);
        
        return res;
    }
};