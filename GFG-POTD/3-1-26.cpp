#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution {
    Node* merge(Node* h1, Node*h2){
        Node* dummy = new Node(-1);
        Node* ptr = dummy;
        
        while(h1 && h2){
            if(h1->data < h2->data){
                ptr->bottom = h1;
                ptr = h1;
                h1 = h1->bottom;
            }else{
                ptr->bottom = h2;
                ptr = h2;
                h2 = h2->bottom;
            }
        }
        
        while(h1){
            ptr -> bottom = h1;
            ptr = h1;
            h1 = h1->bottom;
        }
        
        while(h2){
            ptr -> bottom = h2;
            ptr = h2;
            h2 = h2->bottom;
        }
        
        return dummy->bottom;
    }
  public:
    Node *flatten(Node *root) {
        Node* prev = NULL;
        Node* curr = root;
        
        while(curr){
            prev = merge(prev,curr);
            Node* next = curr->next;
            curr->next = NULL;
            curr = next;
        }
        return prev;
    }
};