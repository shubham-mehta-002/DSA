#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;

public:
    int getNextValidIndex(vector<vector<int>> &events, int startTime, int l, int h)
    {
        int ans = n;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            if (events[mid][0] > startTime)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
    int find(int index, vector<vector<int>> &events, int k)
    {
        if (k == 0)
            return 0;
        if (index == n)
        {
            return 0;
        }

        // take
        int nextValidIndex = getNextValidIndex(events, events[index][1], index + 1, n - 1);
        int take = events[index][2] + find(nextValidIndex, events, k - 1);

        // not take
        int notTake = find(index + 1, events, k);

        return max(take, notTake);
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // base case : k == 0; -> already 0 during intialization
        for (int index = 0; index <= n; index++)
        {
            dp[n][0] = 0;
        }

        // base case : index == n -> already 0 during intialization
        for (int rem = 1; rem <= k; rem++)
        {
            dp[n][rem] = 0;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int rem = 1; rem <= k; rem++)
            {
                // take
                int nextValidIndex = getNextValidIndex(events, events[index][1], index + 1, n - 1);
                int take = events[index][2] + dp[nextValidIndex][rem - 1];

                // not take
                int notTake = dp[index + 1][rem];

                dp[index][rem] = max(take, notTake);
            }
        }

        return dp[0][k];
    }
};