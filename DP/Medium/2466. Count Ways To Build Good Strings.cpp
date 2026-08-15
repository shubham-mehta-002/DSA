#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, 0);

        for (int i = low; i <= high; i++)
        {
            dp[i] = 1;
        }

        for (int index = high - 1; index >= 0; index--)
        {
            dp[index] += ((index + zero <= high ? dp[index + zero] : 0) + (index + one <= high ? dp[index + one] : 0)) % MOD;
        }

        return dp[0];
    }
};