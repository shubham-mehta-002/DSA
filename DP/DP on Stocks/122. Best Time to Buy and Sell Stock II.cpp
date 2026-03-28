#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        vector<int> prev(2, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            vector<int> curr(2, 0);
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int maxProfit = 0;
                if (canBuy)
                {
                    maxProfit = max({maxProfit,
                                     -prices[index] + prev[!canBuy]});
                }
                else
                {
                    maxProfit = max({maxProfit,
                                     prices[index] + prev[!canBuy]});
                }

                maxProfit = max({maxProfit,
                                 prev[canBuy]});

                curr[canBuy] = maxProfit;
            }

            prev = curr;
        }

        return prev[1];
    }
};