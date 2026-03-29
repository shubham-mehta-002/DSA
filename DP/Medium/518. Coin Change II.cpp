#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // base case
        for (int i = 0; i <= amount; i++)
        {
            dp[0][i] = (i % coins[0] == 0 ? 1 : 0);
        }

        for (int index = 1; index < n; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                long long take = 0;
                if (target >= coins[index])
                {
                    take = dp[index][target - coins[index]];
                }
                long long notTake = dp[index - 1][target];
                dp[index][target] = (int)(take + notTake);
            }
        }
        return dp[n - 1][amount];
    }
};