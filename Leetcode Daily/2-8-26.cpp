#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mem[500][500];
    int get(vector<vector<int>> &dp, int i, int j)
    {
        if (i > j)
            return 0;
        return dp[i][j];
    }

public:
    int find(int i, int j, vector<int> &piles)
    {
        if (i > j)
            return 0;
        if (i == j)
            return piles[i];

        if (mem[i][j] != -1)
        {
            return mem[i][j];
        }

        return mem[i][j] = max(
                   piles[i] - find(i + 1, j, piles),
                   piles[j] - find(i, j - 1, piles));
    }

    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                dp[i][j] = max(
                    piles[i] - get(dp, i + 1, j),
                    piles[j] - get(dp, i, j - 1));
            }
        }
        return dp[0][n - 1];
    }
};