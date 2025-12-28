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
    int minValue(Node* root) {
        // code here
        int val = INT_MAX;
        while(root){
            val = min(val,root->data);
            root = root->left;
        }
        return val;
    }
};