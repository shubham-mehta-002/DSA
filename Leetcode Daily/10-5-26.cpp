#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(n, -2);

        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int maxx = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (abs(nums[j] - nums[i]) <= target)
                {
                    int steps = dp[j];
                    if (steps != -1)
                    {
                        maxx = max(maxx, 1 + steps);
                    }
                }
            }

            dp[i] = maxx;
        }
        return dp[0];
    }
};