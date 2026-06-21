#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        vector<int> freq(coins + 1, 0);

        for (int c : costs)
        {
            if (c <= coins)
                freq[c]++;
        }

        int res = 0;
        int remainingCoins = coins;

        for (int i = 1; i <= coins && i <= remainingCoins; i++)
        {
            int temp = min(remainingCoins / i, freq[i]); // buy as many bars of cost i as possible

            remainingCoins -= temp * i; // spend coins
            res += temp;                // increase answer
        }

        return res;
    }
};