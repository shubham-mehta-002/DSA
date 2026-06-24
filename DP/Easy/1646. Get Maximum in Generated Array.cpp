#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 1;

        int maxx = 1;

        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                dp[i] = dp[i / 2];
            }
            else
            {
                dp[i] = dp[i / 2] + dp[(i / 2) + 1];
            }

            maxx = max(maxx, dp[i]);
        }

        return maxx;
    }
};