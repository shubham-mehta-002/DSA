#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxx = 0;
        int n = heights.size();

        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int idx = st.top();
                st.pop();
                int width = (i - (st.empty() ? -1 : st.top())) - 1;

                maxx = max({maxx,
                            heights[idx] * width});
            }

            st.push(i);
        }

        return maxx;
    }
};