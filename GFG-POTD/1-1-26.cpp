#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node* h1 = head1;
        Node* h2 = head2;
        
        while(h1 != h2){
            if(h1 == NULL){
                h1 = head2;
            }
            if(h2 == NULL){
                h2 = head1;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        return h1;
    }
};