#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findSubarraysMax(vector<int> &nums)
    {
        long long total = 0;
        int n = nums.size();

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                int idx = st.top();
                int right = i - idx;
                st.pop();
                int left = idx - (st.empty() ? -1 : st.top());

                total += (right * left * 1LL * nums[idx]);
            }

            st.push(i);
        }

        while (!st.empty())
        {
            int idx = st.top();
            int right = n - idx;
            st.pop();
            int left = idx - (st.empty() ? -1 : st.top());

            total += (right * left * 1LL * nums[idx]);
        }
        return total;
    }

    long long findSubarraysMin(vector<int> &nums)
    {

        long long total = 0;
        int n = nums.size();

        stack<int> st;

        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && nums[st.top()] >= nums[i])
            {

                int idx = st.top();
                st.pop();

                int right = i - idx;
                int left = idx - (st.empty() ? -1 : st.top());

                total += 1LL * nums[idx] * left * right;
            }

            st.push(i);
        }

        while (!st.empty())
        {

            int idx = st.top();
            st.pop();

            int right = n - idx;
            int left = idx - (st.empty() ? -1 : st.top());

            total += 1LL * nums[idx] * left * right;
        }

        return total;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        return findSubarraysMax(nums) - findSubarraysMin(nums);
    }
};