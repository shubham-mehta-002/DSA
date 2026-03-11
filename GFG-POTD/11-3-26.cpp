#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubMins(vector<int> &arr)
    {
        // find nse * pse * arr[i];
        int n = arr.size();

        vector<int> nse(n, -1);
        vector<int> pse(n, n);

        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }

            if (st.empty())
            {
                nse[i] = n;
            }
            else
            {
                nse[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] < arr[st.top()])
            {
                st.pop();
            }

            if (st.empty())
            {
                pse[i] = -1;
            }
            else
            {
                pse[i] = st.top();
            }
            st.push(i);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += (i - pse[i]) * (nse[i] - i) * arr[i];
        }

        return count;
    }
};