#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int subsequencePairCount(vector<int> &nums)
    {
        int maxVal = 0;
        for (int n : nums)
        {
            maxVal = max(maxVal, n);
        }

        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(maxVal + 1, vector<int>(maxVal + 1, 0)));

        // base case
        for (int gcd1 = 0; gcd1 < maxVal + 1; gcd1++)
        {
            for (int gcd2 = 0; gcd2 < maxVal + 1; gcd2++)
            {
                if (gcd1 == 0 || gcd2 == 0 || gcd1 != gcd2)
                {
                    dp[n][gcd1][gcd2] = 0;
                }
                else
                {
                    dp[n][gcd1][gcd2] = 1;
                }
            }
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int gcd1 = 0; gcd1 < maxVal + 1; gcd1++)
            {
                for (int gcd2 = 0; gcd2 < maxVal + 1; gcd2++)
                {
                    long long res = 0;

                    // put in seq1
                    res += dp[index + 1][__gcd(gcd1, nums[index])][gcd2];

                    // put in seq2
                    res += dp[index + 1][gcd1][__gcd(gcd2, nums[index])];

                    // skip
                    res += dp[index + 1][gcd1][gcd2];

                    dp[index][gcd1][gcd2] = (res % MOD);
                }
            }
        }

        return dp[0][0][0];
    }
};