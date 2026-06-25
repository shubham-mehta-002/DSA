#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertInSortedWay(stack<int> &st, int val)
    {
        if (st.empty() || st.top() < val)
        {
            st.push(val);
            return;
        }

        int top = st.top();
        st.pop();

        insertInSortedWay(st, val);

        st.push(top);
    }
    void sort_st(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }

        int top = st.top();
        st.pop();

        sort_st(st);

        insertInSortedWay(st, top);
    }
    void sortStack(stack<int> &st)
    {
        sort_st(st);
    }
};
