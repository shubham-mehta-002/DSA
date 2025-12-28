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
    int findCeil(Node* root, int x) {
        // code here
        int val = -1;
        Node* curr = root;
        while(curr){
            if(curr->data >= x){
                val = curr->data;
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        
        return val;
    }
};
