#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        for (int n : asteroids)
        {
            bool canPush = true;
            while (!st.empty() && st.top() > 0 && n < 0 && canPush)
            {
                if (abs(n) > abs(st.top()))
                {
                    st.pop();
                }
                else if (!st.empty() && abs(st.top()) == abs(n))
                {
                    st.pop();
                    canPush = false;
                }
                else
                {
                    canPush = false;
                }
            }

            if (canPush)
            {
                st.push(n);
            }
        }

        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};