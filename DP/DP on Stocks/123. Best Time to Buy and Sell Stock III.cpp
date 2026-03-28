#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            vector<vector<int>> curr(2, vector<int>(3, 0));

            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int transactionsLeft = 2; transactionsLeft > 0; transactionsLeft--)
                {
                    int maxProfit = 0;

                    if (canBuy)
                    {
                        maxProfit = max({maxProfit,
                                         -prices[index] + next[0][transactionsLeft]});
                    }
                    else
                    {
                        maxProfit = max({maxProfit,
                                         prices[index] + next[1][transactionsLeft - 1]});
                    }

                    maxProfit = max({maxProfit,
                                     next[canBuy][transactionsLeft]});

                    curr[canBuy][transactionsLeft] = maxProfit;
                }
            }
            next = curr;
        }

        return next[1][2];
    }
};