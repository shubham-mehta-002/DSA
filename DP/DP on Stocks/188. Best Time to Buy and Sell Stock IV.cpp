#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> next(k + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            vector<vector<int>> curr(k + 1, vector<int>(2, 0));
            for (int transactionLeft = k; transactionLeft > 0; transactionLeft--)
            {
                for (int canBuy = 0; canBuy <= 1; canBuy++)
                {

                    int maxProfit = 0;
                    if (canBuy)
                    {
                        maxProfit = max(maxProfit, -prices[index] + next[transactionLeft][0]);
                    }
                    else
                    {
                        maxProfit = max(maxProfit, prices[index] + next[transactionLeft - 1][1]);
                    }

                    maxProfit = max(maxProfit, next[transactionLeft][canBuy]);
                    curr[transactionLeft][canBuy] = maxProfit;
                }
            }
            next = curr;
        }

        return next[k][1];
    }
};