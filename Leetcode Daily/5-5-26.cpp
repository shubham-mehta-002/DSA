#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int findLength(ListNode *head)
    {
        int counter = 0;
        while (head != NULL)
        {
            counter++;
            head = head->next;
        }
        return counter;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }
        int length = findLength(head);
        if (k % length == 0)
        {
            return head;
        }
        int movesRequired = length - k % length - 1;

        ListNode *temp = head;
        while (temp != NULL && movesRequired > 0)
        {
            movesRequired--;
            temp = temp->next;
        }

        ListNode *next = temp->next, *newHead = next;
        while (next->next != NULL)
        {
            next = next->next;
        }

        next->next = head;
        temp->next = NULL;
        return newHead;
    }
};