#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(int n)
    {
        vector<int> coins = {1, 2, 5, 10};
        int coinsUsed = 0;
        int i = 3;

        while (n && i >= 0)
        {
            int temp = (n / coins[i]);
            coinsUsed += temp;
            n -= temp * coins[i];
            i--;
        }

        return coinsUsed;
    }
};