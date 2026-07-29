#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        int maxNo = sqrt(n);

        vector<vector<int>> dp(maxNo + 2, vector<int>(n + 1, 1e5));

        // base case
        for (int i = 0; i < maxNo + 2; i++)
        {
            dp[i][0] = 0;
        }

        // for(int target = 1; target <= n; target++){
        //     dp[maxNo][target] = 1e5;
        // }

        for (int i = maxNo; i >= 1; i--)
        {
            for (int target = 1; target <= n; target++)
            {
                int take = INT_MAX;
                if (i * i <= target)
                {
                    take = 1 + dp[i][target - i * i];
                }

                int notTake = dp[i + 1][target];

                dp[i][target] = min(take, notTake);
            }
        }

        return dp[1][n];
    }
};