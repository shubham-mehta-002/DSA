#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int maxProfit = 0;
                if (canBuy)
                {
                    maxProfit = max(maxProfit, -prices[index] + dp[index + 1][0]);
                }
                else
                {
                    maxProfit = max(maxProfit, prices[index] + (index + 2 < n ? dp[index + 2][1] : 0));
                }

                maxProfit = max(maxProfit, dp[index + 1][canBuy]);

                dp[index][canBuy] = maxProfit;
            }
        }

        return dp[0][1];
    }
};