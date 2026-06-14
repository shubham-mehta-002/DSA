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
    int pairSum(ListNode *head)
    {
        stack<int> st;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            st.push(slow->val);

            slow = slow->next;
            fast = fast->next->next;
        }

        int maxx = 0;
        while (slow)
        {
            int top = st.top();
            st.pop();

            maxx = max(maxx, top + slow->val);
            slow = slow->next;
        }

        return maxx;
    }
};