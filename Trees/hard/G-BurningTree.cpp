#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    void traverse(Node* root,unordered_map<Node*,Node*>&m, Node*parent,Node* &targetNode, int target){
        if(!root){
            return;
        }
        
        if(root->data == target){
            targetNode = root;
        }

        m[root] = parent;
        traverse(root->left,m,root,targetNode, target);
        traverse(root->right,m,root,targetNode, target);
    }
    int minTime(Node* root, int target) {
        int time = 0;
        if(!root)   return time;
       

        unordered_map<Node*,Node*>m;
        unordered_map<Node*,int>vis;
        
        Node* targetNode = NULL;
        traverse(root,m,NULL,targetNode,target);
        
        if(!targetNode){
            return time;
        }
        
        queue<Node*>q;
        q.push(targetNode);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node*top = q.front();
                q.pop();
                vis[top] = 1;
                
                if(top->left && !vis[top->left]) q.push(top->left);
                if(top->right && !vis[top->right]) q.push(top->right);
                if(m[top] && !vis[m[top]]) q.push(m[top]);
            }
            time++;
        }
        return time-1;
        
    }
};