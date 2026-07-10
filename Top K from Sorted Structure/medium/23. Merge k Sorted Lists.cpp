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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *dummy = new ListNode(-1);

        using pp = pair<int, ListNode *>;

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for (auto l : lists)
        {
            if (l)
            {
                pq.push({l->val, l});
            }
        }

        ListNode *curr = dummy;

        while (!pq.empty())
        {
            pp top = pq.top();
            pq.pop();

            curr->next = top.second;
            curr = curr->next;

            if (curr->next)
            {
                pq.push({curr->next->val, curr->next});
            }
        }

        return dummy->next;
    }
};