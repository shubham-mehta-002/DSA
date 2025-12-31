// https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};


class Solution {
  public:
    Node* findMid(Node* head){
        Node* slow = head, *fast = head,*prev= NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    Node* reverse(Node* head){
        Node*prev = NULL, *next = NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool checkIfPalindrome(Node* h1,Node*h2){
        while(h1){
            if(h1->data != h2->data)    return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
    bool isPalindrome(Node *head) {
        if(!head || !head->next){
            return true;
        }
        
        Node* prevToMid = findMid(head);
        Node* mid = prevToMid->next;
        prevToMid -> next = NULL;
        
        Node* reversedLL = reverse(mid);
        
        bool isPalindrome = checkIfPalindrome(head,reversedLL);
        prevToMid -> next = reverse(reversedLL);
        return isPalindrome;        
    }
};