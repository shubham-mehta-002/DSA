//https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

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
    void attachNode(Node*& head,Node*&tail, Node* p1,Node*p2,int &carry){
        int sum = ((p1 ? p1->data : 0 )+ (p2 ? p2->data : 0) + carry);
        int rem = (sum )%10;
        carry = sum/10;
        Node* newNode = new Node(rem);
        if(head == NULL){
            // cout<<"yes ";
            head = tail = newNode;
        }else{
            // cout<<"no ";
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL, *next = NULL;
        while(head){
            next = head->next;
            head ->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // remove all the leading zeros;
        Node* h1 = head1;
        Node* h2 = head2;
        
        while(h1 && h1->data == 0){
            h1 = h1->next;
        }
        
        while(h2 && h2->data == 0){
            h2 = h2->next;
        }
        
        Node* head = NULL;
        Node* tail = NULL;
        
        // reverse
        Node* rev_h1 = reverse(h1);
        Node* rev_h2 = reverse(h2);
        
        // sum
        int carry = 0;
        while(rev_h1 && rev_h2){
            
            
            attachNode(head,tail,rev_h1,rev_h2,carry);
            
            rev_h1 = rev_h1->next;
            rev_h2 = rev_h2->next;
        }
        
        while(rev_h1){
            attachNode(head,tail,rev_h1,rev_h2,carry);
            rev_h1 = rev_h1->next;
        }
        
        while(rev_h2){
            attachNode(head,tail,rev_h1,rev_h2,carry);
            rev_h2 = rev_h2->next;
        }
        
        
        if(carry){
            attachNode(head,tail,NULL,NULL,carry);
        }
        
        head = reverse(head);
        
        reverse(h1);
        reverse(h2);
        
        return head;
        
    }
};