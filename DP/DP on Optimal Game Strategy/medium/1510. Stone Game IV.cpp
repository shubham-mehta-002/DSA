#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // O(n * sqrt(n))
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);

        for (int piles = 1; piles <= n; piles++)
        {
            int maxx = (int)sqrt(piles);

            int ans = false;
            for (int i = 1; i <= maxx; i++)
            {
                if (dp[piles - i * i] == false)
                {
                    ans = true;
                    break;
                }
            }
            dp[piles] = ans;
        }

        return dp[n];
    }
};