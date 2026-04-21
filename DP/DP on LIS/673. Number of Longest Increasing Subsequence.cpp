#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ways(n, 1);
        vector<int> dp(n, 1);

        int maxx = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        ways[i] = ways[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        ways[i] += ways[j];
                    }
                }
            }
            maxx = max(maxx, dp[i]);
        }

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxx)
            {
                total += ways[i];
            }
        }

        return total;
    }
};