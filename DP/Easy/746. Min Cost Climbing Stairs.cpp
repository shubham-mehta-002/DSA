#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 2, 0);

        dp[n - 1] = cost[n - 1];

        for (int index = n - 2; index >= 0; index--)
        {
            int minn = INT_MAX;

            // 1 step
            minn = min(minn, dp[index + 1]);

            // 2 step
            minn = min(minn, dp[index + 2]);

            dp[index] = minn + cost[index];
        }

        return min(dp[0], dp[1]);
    }
};