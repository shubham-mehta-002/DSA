#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &arr)
    {
        // next smallest element
        int n = arr.size();

        stack<int> st;
        int count = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                count += n - i;
            }
            else
            {
                count += st.top() - i;
            }

            st.push(i);
        }

        return count;
    }
};