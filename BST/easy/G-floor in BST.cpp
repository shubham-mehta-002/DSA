#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int findFloor(Node* root, int x) {
        int val = -1;
        Node* curr = root;
        while(curr){
            if(curr->data > x){
                curr = curr->left;
            }else{
                val =curr->data;
                curr = curr->right;
            }
        }
        
        return val;
    }
};