#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int maxVal = prices[prices.size() - 1];

        for (int i = prices.size() - 2; i >= 0; i--)
        {
            maxProfit = max(maxProfit, maxVal - prices[i]);
            maxVal = max(maxVal, prices[i]);
        }
        return maxProfit;
    }
};