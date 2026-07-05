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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummySmaller = new ListNode(-1);
        ListNode *dummyGreater = new ListNode(-1);

        ListNode *smaller = dummySmaller;
        ListNode *greater = dummyGreater;

        ListNode *temp = head;

        while (temp)
        {
            if (temp->val >= x)
            {
                greater->next = temp;
                greater = greater->next;
            }
            else
            {
                smaller->next = temp;
                smaller = smaller->next;
            }

            temp = temp->next;
        }

        smaller->next = dummyGreater->next;
        greater->next = NULL;

        return dummySmaller->next;
    }
};