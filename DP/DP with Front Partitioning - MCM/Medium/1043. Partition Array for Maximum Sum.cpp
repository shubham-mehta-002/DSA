#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // base case
        for (int state = 0; state <= k; state++)
        {
            dp[n][k] = 0;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int state = 0; state <= k; state++)
            {
                int finalRes = 0;
                int maxVal = 0;
                for (int i = index; i < min(k + index, (int)arr.size()); i++)
                {
                    maxVal = max(maxVal, arr[i]);
                    finalRes = max(finalRes, maxVal * (i - index + 1) + dp[i + 1][k]);
                }

                dp[index][state] = finalRes;
            }
        }

        return dp[0][0];
    }
};