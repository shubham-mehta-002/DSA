#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
    stack<pair<int, int>> st;
    int day;

public:
    StockSpanner()
    {
        day = 0;
    }

    int next(int price)
    {
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }

        day++;
        int val;
        if (st.empty())
        {
            val = day;
        }
        else
        {
            val = day - st.top().second;
        }

        st.push({price, day});
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */