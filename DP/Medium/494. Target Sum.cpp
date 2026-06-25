#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int offset = 0;
        for (int num : nums)
            offset += num;

        if (target < -offset || target > offset)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2 * offset + 1, 0));

        vector<int> prev(2 * offset + 1, 0);
        // base case
        if (nums[0] == 0)
            prev[0 + offset] = 2;
        else
        {
            prev[nums[0] + offset] = 1;
            prev[-nums[0] + offset] = 1;
        }

        for (int index = 1; index < n; index++)
        {
            vector<int> current(2 * offset + 1, 0);
            for (int curr = -offset; curr <= offset; curr++)
            {
                int ways = 0;
                // take
                if (curr + nums[index] <= offset)
                    ways += prev[curr + offset + nums[index]];
                // not take
                if (curr - nums[index] >= -offset)
                    ways += prev[curr + offset - nums[index]];

                current[curr + offset] = ways;
            }
            prev = current;
        }

        return prev[target + offset];
    }
};