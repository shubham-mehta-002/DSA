#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // base case : from > to
        for (int to = 0; to <= n; to++)
        {
            for (int from = to + 1; from <= n + 1; from++)
            {
                dp[from][to] = 1;
            }
        }

        for (int from = n; from >= 1; from--)
        {
            for (int to = from; to <= n; to++)
            {
                int ans = 0;
                for (int node = from; node <= to; node++)
                {
                    int left = dp[from][node - 1];
                    int right = dp[node + 1][to];

                    ans += left * right;
                }

                dp[from][to] = ans;
            }
        }

        return dp[1][n];
    }
};