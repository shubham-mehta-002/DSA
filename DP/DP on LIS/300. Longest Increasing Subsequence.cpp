#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> next(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            vector<int> curr(n + 1, 0);
            for (int lastIndex = index - 1; lastIndex >= -1; lastIndex--)
            {
                int maxLen = 0;
                // take
                if (lastIndex == -1 || (lastIndex > -1 && nums[lastIndex] < nums[index]))
                {
                    maxLen = max(maxLen, 1 + next[index + 1]);
                }

                // not take
                maxLen = max(maxLen, next[lastIndex + 1]);

                curr[lastIndex + 1] = maxLen;
            }

            next = curr;
        }

        return next[0];
    }
};