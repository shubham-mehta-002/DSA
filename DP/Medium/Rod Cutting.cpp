#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // base case
        for (int capacity = 0; capacity <= n; capacity++)
        {
            dp[0][capacity] = capacity * price[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int capacity = 0; capacity <= n; capacity++)
            {
                int take = 0;
                if (capacity >= index + 1)
                {
                    take = price[index] + dp[index][capacity - (index + 1)];
                }

                int notTake = dp[index - 1][capacity];

                dp[index][capacity] = max(take, notTake);
            }
        }
        return dp[n - 1][n];
    }
};