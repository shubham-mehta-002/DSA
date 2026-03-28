#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<int> next(2, 0);

        int n = prices.size();

        for (int index = n - 1; index >= 0; index--)
        {
            vector<int> curr(2, 0);
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int maxProfit = 0;
                if (canBuy)
                {
                    maxProfit = max(maxProfit, -prices[index] + next[0]);
                }
                else
                {
                    maxProfit = max(maxProfit, -fee + prices[index] + next[1]);
                }

                maxProfit = max(maxProfit, next[canBuy]);

                curr[canBuy] = maxProfit;
            }
            next = curr;
        }

        return next[1];
    }
};