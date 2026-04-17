#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> parent(n, -1);
        vector<int> dp(n, 1);
        int maxx = 1;
        int maxIdx = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > maxx)
                    {
                        maxx = dp[i];
                        maxIdx = i;
                    }
                }
            }
        }

        vector<int> res;
        int start = maxIdx;
        while (start != -1)
        {
            res.push_back(nums[start]);
            start = parent[start];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};