#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<pair<int, int>> dq;

        dq.push_back({nums[0], 0});
        int maxx = nums[0];

        for (int i = 1; i < n; i++)
        {
            // pop out of bound indices;
            while (!dq.empty() && i - dq.front().second > k)
            {
                dq.pop_front();
            }

            int currVal = max(dq.front().first + nums[i], nums[i]);

            maxx = max(maxx, currVal);

            // insert into deque
            while (!dq.empty() && dq.back().first < currVal)
            {
                dq.pop_back();
            }
            dq.push_back({currVal, i});
        }

        return maxx;
    }
};