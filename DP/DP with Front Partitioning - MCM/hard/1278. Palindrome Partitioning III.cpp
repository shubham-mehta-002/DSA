#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    int cost_mem[101][101];

public:
    int costToConvertIntoPalin(int i, int j, string &s)
    {
        if (i > j)
            return 0;

        if (cost_mem[i][j] != -1)
        {
            return cost_mem[i][j];
        }

        int cost = 0;
        if (s[i] != s[j])
        {
            cost += 1;
        }
        cost += costToConvertIntoPalin(i + 1, j - 1, s);

        return cost_mem[i][j] = cost;
    }

    int palindromePartition(string s, int k)
    {
        n = s.size();
        memset(cost_mem, -1, sizeof(cost_mem));

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // base case : when k == 1;
        for (int index = 0; index < n; index++)
        {
            dp[index][1] = costToConvertIntoPalin(index, n - 1, s);
        }

        // bottom-up code
        for (int index = n - 1; index >= 0; index--)
        {
            for (int rem = 2; rem <= k; rem++)
            {
                int minCost = INT_MAX;

                for (int i = index; i <= n - rem; i++)
                {
                    minCost = min(
                        minCost,
                        costToConvertIntoPalin(index, i, s) + dp[i + 1][rem - 1]);
                }

                dp[index][rem] = minCost;
            }
        }

        return dp[0][k];
    }
};