
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int>res;
        if(!root)   return res;
        
        map<int,int>m;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        
        while(!q.empty()){
            const pair<int,Node*>&p = q.front();
            int col = p.first;
            q.pop();
            
            m[p.first] = p.second->data;
            
            
            if(p.second->left){
                q.push({col-1,p.second->left});
            }
            if(p.second->right){
                q.push({col+1,p.second->right});
            }
        }
        
        
        for(map<int,int> ::iterator it = m.begin(); it!=m.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};